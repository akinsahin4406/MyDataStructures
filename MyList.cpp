#include "MyList.h"

template<typename T>
MyList<T>::MyList(std::initializer_list<T> l):
count{0},
head{nullptr},
last{nullptr}
{
    for(const T &t:l)
    {
        push_back(t);
    }
}

template<typename T>
MyList<T>::~MyList()
{
    clear();
}

template<typename T>
void MyList<T>::push_back(T data)
{
    if (count == 0)
    {
        head = new Node<T>(data);
        head->back = nullptr; 
        head->front = nullptr; 
        last = head;
    }
    else
    {
        Node<T>* node = new Node<T>(data);
        last->front = node;
        node->back = last;
        last = node;
    }
    ++count;
}

template<typename T>
void MyList<T>::push_front(T data)
{
    if (count == 0)
    {
        head = new Node<T>(data);
        head->back = nullptr; 
        last = head;
    }
    else
    {
        Node<T>* node = new Node<T>(data);
        head->back = node;
        node->front = head;
        head = node;
    }
    ++count;
}

template<typename T>
void MyList<T>::insert(T newdata, int index)
{
    if (index > count)
        return;

    Node<T>* newnode = new Node<T>(newdata);

    int counter = 0;
    Node<T>* previous_one = head;
    while(counter != index-1)
    {
        previous_one = previous_one->front;
        ++counter;
    }
    Node<T>* next_one = previous_one->front;
    previous_one->front = newnode;
    newnode->back = previous_one;
    newnode->front = next_one;
    next_one->back = newnode;
    ++count;
}

template<typename T>
void MyList<T>::erase(int index)
{
    if (index > count)
        return;

    int counter = 0;
    Node<T>* this_one = head;
    while(counter != index)
    {
        this_one = this_one->front;
        ++counter;
    }
    Node<T>* next_one = this_one->front;
    Node<T>* previous_one =  this_one->back;
    next_one->back = previous_one;
    previous_one->front = next_one;
    delete this_one;
    --count;
}

template<typename T>
void MyList<T>::clear()
{
    if (head == nullptr || last == nullptr)
        return;

    Node<T>* this_one = head;
    do
    {
        Node<T>* front = this_one->front;
        delete this_one;
        --count;
        this_one = front;
    }while(count>0);
}

template<typename T>
void MyList<T>::remove_if(bool (*comparator)(T& val))
{
    Node<T>* this_one = head;
    while(this_one != nullptr)
    {
        Node<T>* next_one = this_one->front;
        std::cout << "remove_if 1" << std::endl;
        if (comparator(this_one->data))
        {
            Node<T>* previous_one =  this_one->back;
            std::cout << "remove_if 2" << std::endl;
            if (next_one != nullptr)
            {
                next_one->back = previous_one;
            }
            else
            {
                last = previous_one;
            }
            std::cout << "remove_if 3" << std::endl;
            if (previous_one != nullptr)
            {
                previous_one->front = next_one;
            }
            else
            {
                head = next_one;
            }
            std::cout << "remove_if 4" << std::endl;
            delete this_one;
            --count;
        }
        std::cout << "remove_if 5" << std::endl;
        this_one = next_one;
    }
}

template<typename T>
T& MyList<T>::operator [] (int index)
{
    int counter = 0;
    Node<T>* this_one = head;
    while(counter != index)
    {
        this_one = this_one->front;
        ++counter;
    }
    return this_one->data;
}

template<typename T>
T MyList<T>::pop_back()
{
    T ret = last->data;
    last = last->back;
    last->front = nullptr;
    return ret;
}

template<typename T>
T MyList<T>::pop_front()
{
    T ret = head->data;
    head = head->front;
    head->back = nullptr;
    return ret;
}

template<typename T>
void MyList<T>::printValues() const
{
    Node<T>* first_one = head;
    while(first_one != last)
    {
        std::cout << "value 0:" << first_one->data << std::endl;
        first_one = first_one->front;
    }
    if (first_one != nullptr)
        std::cout << "value 1:" << first_one->data << std::endl;
}

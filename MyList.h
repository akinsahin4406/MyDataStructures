#pragma once

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <tuple>
#include <memory>
#include <queue>

template<typename T>
struct Node
{
    T data;
    Node(T data):
    data{data}
    {
    }
    Node* back;
    Node* front;
};

template<typename T>
class MyList
{
    Node<T>* head;
    Node<T>* last;
    int count;
    public:
    MyList():
    count{0}
    {

    }
    MyList(std::initializer_list<T> l);
    ~MyList();

    void push_back(T data);

    void push_front(T data);

    void insert(T newdata, int index);
    void erase(int index);
    void clear();
    void remove_if(bool (*comparator)(T& val));

    T& operator [] (int index);
    
    T pop_back();

    T pop_front();

    void printValues() const;
};

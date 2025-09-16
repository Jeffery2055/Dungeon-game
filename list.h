#pragma once
#include "rooms.h"
#include <iostream>

template <class T1>
class List
{
    private:
    Room<T1>* _head;
    Room<T1>* _tail;

    public:
    List();
    ~List();
    bool empty();
    T1 front();
    void push_back(T1);
    T1 pop_front();
    T1 back();
};

template <class T1>
List<T1>::List()
{
    _head = nullptr;
    _tail = nullptr;
}

template <class T1>
List<T1>::~List()
{
    while(_head != nullptr)
    {
        Room<T1>* tempNode = _head;
        _head = _head->getFWD();
        delete tempNode;
    }
    _tail = nullptr;
}

template <class T1>
bool List<T1>::empty()
{
    if(_head == nullptr && _tail == nullptr)
    {
        return true;
    }
    return false;
}

template <class T1>
T1 List<T1>::front()
{
    if(_head == nullptr)
    {
        std::cout << "There are no rooms" << std::endl;
        return 0;
    }
    else
    {
        return _head->getDesc();
    }
}

template <class T1>
T1 List<T1>::pop_front()
{
    if(_head == nullptr && _tail == nullptr)
    {
        std::cout << "There are no rooms" << std::endl;
        return 0;
    }
    else if(_head->getFWD() == nullptr)
    {
        Room<T1>* curNode = new Room<T1>;
        curNode = _head;
        _head = nullptr;
        _tail = nullptr;
        return curNode->getDesc();
    }
    else
    {
        Room<T1>* curNode = new Room<T1>;
        curNode = _head;
        _head = _head->getFWD();
        curNode->setFWD(nullptr);
        _head->setBWD(nullptr);
        return curNode->getDesc();
    }
}

template <class T1>
void List<T1>::push_back(T1 data)
{
    Room<T1>* newNode = new Room<T1>;
    newNode->setDesc(data);
    if(_tail == nullptr && _head == nullptr)
    {
        _tail = newNode;
        _head = newNode;
    }
    else
    {
        _tail->setFWD(newNode);
        newNode->setBWD(_tail);
        _tail = newNode;
    }
}

template <class T1>
T1 List<T1>::back()
{
    if(_tail == nullptr && _head == nullptr)
    {
        std::cout << "There are no rooms" << std::endl;
        return 0;
    }
    else
    {
        return _tail->getDesc();
    }
}
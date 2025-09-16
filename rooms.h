#pragma once
#include <random>

template <class T1>
class Room
{
    private:
    Room<T1>* _forward;
    Room<T1>* _backward;
    T1 _desc;

    public:
    Room<T1>()
    {
        _forward = nullptr;
    }

    void setDesc(T1 desc)
    {
        _desc = desc;
    }

    void setFWD(Room* forward)
    {
        _forward = forward;
    }

    void setBWD(Room* backward)
    {
        _backward = backward;
    }

    T1 getDesc()
    {
        return _desc;
    }

    Room* getFWD()
    {
        return _forward;
    }

    Room* getBWD()
    {
        return _backward;
    }

};
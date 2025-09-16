#pragma once

#include <iostream>

using namespace std;

class Item
{
    private:
    string _name;
    string _effect;

    public:
    Item(string = "Unkown", string = "Uknown");
    void setName(string);
    void setEffect(string);
    string getName();
    string getEffect();
    void use();
};
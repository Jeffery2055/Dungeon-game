#pragma once

#include <iostream>
#include "items.h"

using namespace std;

class Player
{
    private:
    string _name;
    int _health;
    int _attack;
    string inventory[10];

    public:
    Player(string = "Unknown", int = 100, int = 40);
    void setName(string);
    void setHealth(int);
    void setAttack(int);
    void setInventory(int, string);
    string getName();
    int getHealth();
    int getAttack();
    string getInventory(int);
    void addToInventory(string);
    void takeDamage(int damage);
};
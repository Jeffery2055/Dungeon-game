#pragma once

#include <iostream>

using namespace std;

class Enemy
{
    private:
    string _name;
    int _health;
    int _attack;

    public:
    Enemy(string = "Unknown", int = 100, int = 20);
    void setName(string);
    void setHealth(int);
    void setAttack(int);
    string getName();
    int getHealth();
    int getAttack();
    void takeDamage(int);
};
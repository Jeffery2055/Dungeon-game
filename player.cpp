#include "player.h"
#include "items.h"

Player::Player(string name, int health, int attack)
{
    _name = name;
    _health = health;
    _attack = attack;
    for(int i = 0; i < 10; i++)
    {
        inventory[i] = "empty";
    }
}

void Player::setName(string name)
{
    _name = name;
}

void Player::setHealth(int health)
{
    _health = health;
}

void Player::setAttack(int attack)
{
    _attack = attack;
}

void Player::setInventory(int index, string item)
{
    inventory[index] = item;
}

string Player::getName()
{
    return _name;
}

int Player::getHealth()
{
    return _health;
}

int Player::getAttack()
{
    return _attack;
}

string Player::getInventory(int index)
{
    return inventory[index];
}

void Player::addToInventory(string item)
{
    for(int i = 0; i < 10; i++)
    {
        if(inventory[i] == "empty")
        {
            inventory[i] = item;
            break;
        }
        else
        {
            continue;
        }
    }
}

void Player::takeDamage(int damage)
{
    int health = getHealth();

    setHealth(health - damage);
}
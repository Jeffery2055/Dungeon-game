#include "enemy.h"

Enemy::Enemy(string name, int health, int attack)
{
    _name = name;
    _health = health;
    _attack = attack;
}
void Enemy::setName(string name)
{
    _name = name;
}
void Enemy::setHealth(int health)
{  
    _health = health;
}
void Enemy::setAttack(int attack)
{
    _attack = attack;
}
string Enemy::getName()
{
    return _name;
}
int Enemy::getHealth()
{
    return _health;
}
int Enemy::getAttack()
{
    return _attack;
}
void Enemy::takeDamage(int damage)
{
    int health = getHealth();

    setHealth(health - damage);
}
#include "items.h"

Item::Item(string name, string effect)
{
    _name = name;
    _effect = effect;
}
void Item::setName(string name)
{
    _name = name;  
}
void Item::setEffect(string effect)
{
    _effect = effect;
}
string Item::getName()
{
    return _name;
}
string Item::getEffect()
{
    return _effect;
}
void Item::use()
{
    getEffect();
}
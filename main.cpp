#include <iostream>
#include "list.h"
#include "player.h"
#include "enemy.h"
#include "items.h"

using namespace std;

void game();
List<string> genDungeon();
Player combat(Player&, string);

int main(int argc, char* argv[])
{
    game();
    return 0;
}

List<string> genDungeon()
{
    List<string> myDungeon;
    string desc = "you were asked to explore a nearby dungeon for a recipe to make a Potion of Greater Healing.\nA potion that is said to heal any ailment, you find yourself at the entrance to said dungeon. Before you lies a heavy\nstone door, as you push it open and look around this first room you see it covered in vines and other foliage.\nThis structure has been here for a long time. Ahead of you is a archway that leads into a dark hallway.\nWould you like to enter? ";
    myDungeon.push_back(desc);
    
    desc = "As you enter the next room the first thing you notice is a man standing in the center of the room rumaging through\nsomething. Before you can think the man turns his head and sees you, he draws his shortsword and you, your longsword. ";
    myDungeon.push_back(desc);

    desc = "After your engagement with the bandit, you move into the next room, you see no more bandits but a chest instead,\nyou break open this chest, inside you find a Potion of Healing.\n Use? ";
    myDungeon.push_back(desc);

    desc = "Moving further through the dungeon you find another creature, but this is no human, you encounter a giant spider,\na grotesque creature thought to be just a story to scare children. With its eight eyes it spots you and moves to defend its territory";
    myDungeon.push_back(desc);

    desc = "After defeating the spider, you enter the next room, this one without another path to exit out of. You see a large chest\nin the middle of the dungeon this much more ornate than the first chest you found, Inside you find the object of your\nquest: a recipe to craft a Potion of Greater Healing! With your quest completed you turn to leave and return\nto the village. But to your surprise you find a bandit standing at the entrance to the room.";
    myDungeon.push_back(desc);

    return myDungeon;
}

Player combat(Player& player, string enemyName)
{
    Enemy foe;
    char playerChoice;
    if(enemyName == "Bandit")
    {
        foe.setName(enemyName);
    }
    else if(enemyName == "Giant Spider")
    {
        foe.setName(enemyName);
        foe.setHealth(150);
        foe.setAttack(10);
    }
    while(player.getHealth() > 0 && foe.getHealth() > 0)
    {
        cout << endl << player.getName() << " HP: " << player.getHealth() << endl;
        cout << "With your enemy in front of you what do you do? " << endl;
        cout << "Attack with your longsword: [A]" << endl;
        cout << "Use Item [I]" << endl;
        cin >> playerChoice;
        if(playerChoice == 'A' || playerChoice == 'a')
        {
            cout << "You swipe with you longsword and create a large gash in your enemy." << endl;
            foe.takeDamage(player.getAttack());
        }
        else if(playerChoice == 'I' || playerChoice == 'i')
        {
            for(int i = 0; i < 10; i++)
            {
                if(player.getInventory(i) != "empty")
                {
                    string item = player.getInventory(i);
                    if(item == "Potion of Healing")
                    {
                        cout << "You use a Potion of Healing" << endl;
                        player.setHealth(player.getHealth() + 30);
                        player.setInventory(i, "empty");
                    }
                    else
                    {
                        cout << item << " cannot be use din combat" << endl;
                    }
                }
            }
        }

        if(foe.getHealth() > 0)
        {
            cout << "The enemy counterattacks!" << endl;
            player.takeDamage(foe.getAttack());
        }
    }

    return player;
}

void game()
{
    Player player;
    string name;
    char playerChoice;
    cout << "Please enter your name: ";
    getline(cin, name);
    player.setName(name);

    List<string> dungeon = genDungeon();

    cout << player.getName() << ", " << dungeon.pop_front() << endl;
    cin >> playerChoice;
    if(playerChoice == 'y' || playerChoice == 'Y')
    {
        cout << endl << dungeon.pop_front() << endl;
        combat(player, "Bandit");
        if(player.getHealth() > 0)
        {
            Item potionOfHealing("Potion of Healing", "Heals 30 HP");
            char itemUse;
            cout << endl << dungeon.pop_front() << endl;
            cin >> itemUse;
            if(itemUse == 'y' || itemUse == 'Y')
            {
                cout << "You drink the Potion and you feel your wounds from the last battle start to heal" << endl;
                player.setHealth(player.getHealth() + 30);
            }
            else
            {
                cout << "You store the item into your inventory" << endl;
                player.addToInventory(potionOfHealing.getName());
            }

            cout << endl << dungeon.pop_front() << endl;
            combat(player, "Giant Spider");
            if(player.getHealth() > 0)
            {
                cout << endl << dungeon.pop_front() << endl;
                Item recipe("Potion of Greater Healing Recipe", "none");
                player.addToInventory(recipe.getName());
                combat(player, "Bandit");
                if(player.getHealth() > 0)
                {
                    cout << "You succesfully retireved the Potion of Greater Healing from the dungeon and gave it to the village. You have completed your quest. Congratualtions!" << endl;
                }
                else
                {
                    cout << "You have been vanquished" << endl;
                }
            }
            else
            {
                cout << "You have been vanquished" << endl;
            }
        }
        else
        {
            cout << "You have been vanquished" << endl;
        }
    }
    else
    {
        cout << "Why would you pick this" << endl;
    }

}
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <random>
#include <thread>
#include <chrono>
#include "file.h"
using namespace std;

struct character {
    int health = 3;
    int strength;
    int agility;
    int defense;
};

//Take input and check validity depending on maxChoice.
int numInput(int maxChoice) {
    int input;
    while (true) {
        cout << "Enter a number: ";
        cin >> input;
        while (!(input >= 1 && input <= maxChoice)) {
            cout << "Invalid input, please enter a number between 1 and " << maxChoice << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            cin.clear(); // Clear the failbit
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a number: ";
            cin >> input;
        }
        break;
    }
    return input;
}

//Take input for menu page and check for validity
int menuInput() {
    int input;
    while (true) {
        welcome();
        cout << "Enter a number: ";
        cin >> input;
        while (!(input >= 1 && input <= 3)) {
            cout << "Invalid input, please enter a number between 1 and 3."<< endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            welcome();
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a number: ";
            cin >> input;
        }
        break;
    }
    return input;
}

//Check if character is dead
bool dead(character* c) {
    return(c->health == 0);
}

//Press enter to continue
void pressEnterToContinue() {
    cout << "   [Press Enter to continue...]    ";
    cin.sync();
    cin.clear();
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cin.ignore();
}

//Print character status
void printStatus(character* c) {
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Player Status: " << endl;
    cout << "Health: " << c->health << endl;
    cout << "Strength: " << c->strength << endl;
    cout << "Agility: " << c->agility << endl;
    cout << "Defense: " << c->defense << endl;
    pressEnterToContinue();
    return;
}

//Upgrade character
void upgrade(character* c) {
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "You can choose one attribute to upgrade:" << endl;
    cout << "1. Strenght" << endl;
    cout << "2. Agility" << endl;
    cout << "3. Defense" << endl;
    int choice = numInput(3);
    switch (choice)
    {
    case 1:
        c->strength++;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "Strength has been upgraded." << endl;
        printStatus(c);
        break;
    case 2:
        c->agility++;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "Agility has been upgraded." << endl;
        printStatus(c);
        break;
    case 3:
        c->defense++;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "Defense has been upgraded." << endl;
        printStatus(c);
        break;
    default:
        break;
    }
    return;
}

//Judge the result of certain combat and change health bar accordingly
void judge(int move, int x, character* p, character* m) {
    switch (move)
    {
    case(1): {
            if (p->strength*x > m->strength) {
                m->health--;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "Your strength is higher" << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "The monster lost 1 hp" << endl;
            }
            else if (p->strength * x < m->strength) {
                p->health--;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "Monster's strength is higher" << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "You lost 1 hp" << endl;
            }
            else {
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "It was a tie" << endl;
            }
            break;
        }
        case(2): {
            if (p->agility * x > m->agility) {
                m->health--;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "Your agility is higher" << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "The monster lost 1 hp" << endl;
            }
            else if (p->agility * x < m->agility) {
                p->health--;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "Monster's agility is higher" << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "You lost 1 hp" << endl;
            }
            else {
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "It was a tie" << endl;
            }
            break;
        }
        case(3): {
            if (p->defense * x > m->defense) {
                m->health--;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "Your defense is higher" << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "The monster lost 1 hp" << endl;
            }
            else if (p->defense * x < m->defense) {
                p->health--;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "Monster's defense is higher" << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "You lost 1 hp" << endl;
            }
            else {
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "It was a tie" << endl;
            }
            break;
        }
        default:
            break;
    }
}

//Initiate combat between characters
void combat(character* p, character* m) {
    printStatus(p);
    cout << "Pick a move: " << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "1. Attack" << endl;
    cout << "2. Stealth" << endl;
    cout << "3. Parry" << endl;
    int move = numInput(3);
    int monster_move = rand() % 3 + 1;

    switch (monster_move)
    {
    case(1): {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "The monster chose to attack" << endl;
        break;
    }
    case(2): {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "The monster chose to stealth" << endl;
        break;
    }
    case(3): {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "The monster chose to parry" << endl;
        break;
    }
    default:
        break;
    }

    if (move == monster_move) {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "Fair Play" << endl;
        judge(move, 1, p, m);
    }
    //counter
    else if ((move == monster_move-1)||(move == 3 && monster_move == 1)) {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "COUNTER" << endl;
        judge(move, 2, p, m);
    }
    //countered by monster
    else{
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "countered by monster" << endl;
        judge(move, 0.5, p, m);
    }
}

//Game logic
int game() {
    cout << endl << endl << endl << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "You woke up at the bottom of a dark tower," << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "the only way to escape is to go up into darkness..." << endl;
    pressEnterToContinue();
    character* player = new character;
    string* feature = adj();
    string* name = monster();
    player->strength = 1;
    player->agility = 1;
    player->defense = 1;
    int round = 0;
    srand(time(nullptr));
    while (true) {
        round ++;
        player->health = 3;
        string monster_name = feature[rand() % 30] + " " + name[rand() % 30];
        character* monster = new character;
        int monster_total = round + 2;
        monster->strength = rand() % monster_total + 1;
        monster_total -= monster->strength;
        monster->agility = (monster_total != 0) ? (rand() % monster_total + 1) : 0;
        monster_total -= monster->agility;
        monster->defense = (monster_total != 0) ? monster_total : 0;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "You entered floor " << round << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "There is a " << monster_name << endl;
        while (!(player->health == 0 || monster->health == 0)) {
            cout << "----------------------------------------------" << endl;
            combat(player, monster);
            cout << "----------------------------------------------" << endl;
        }

        if (dead(player)) {
            break;
        }

        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "The monster is defeated." << endl;
        upgrade(player);
        delete(monster);
    }
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "   YOU DIED    " << endl;
    delete(player);
    return round;
}

//Menu page
void menu() {
    int choice = menuInput();
    while (choice != 3) {
        if (choice == 1) {
            int score = game();
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "Your Score: " << score << endl;
            pressEnterToContinue();
        }
        else if (choice == 2) {
            guide();
            pressEnterToContinue();
        }
        choice = menuInput();
    }
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Thanks for playing, Bye :D" << endl;
    return;
}

int main() {
	menu();
	return 1;
}



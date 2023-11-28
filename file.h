#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Read welcome text from file 
void welcome() {
    ifstream file("welcome.txt");

    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return;
}

//Read guide text from file 
void guide() {
    ifstream file("guide.txt");

    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return;
}

//Read adjective words for monsters from file 
string* adj() {
    string* adj = new string[30];
    ifstream file("adj.txt");

    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return NULL;
    }

    string line;
    for (int i = 0; i < 30; i++) {
        getline(file, line);
        adj[i] = line;
    }

    file.close();
    return adj;
}

//Read monster names from file 
string* monster() {
    string* monster = new string[30];
    ifstream file("monster.txt");

    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return NULL;
    }

    string line;
    for (int i = 0; i < 30; i++) {
        getline(file, line);
        monster[i] = line;
    }

    file.close();
    return monster;
}

#endif

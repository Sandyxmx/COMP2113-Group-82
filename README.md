# COMP2113-Group-82
Group 82

# Group Members #
Xiang Mengxuan UID 3035603265
Zhuang Jinming UID 3035951820

# Game Descriptions #
In Monster Arena, you will encounter one monster each level
Upon defeating the monster, you can choose one out of the three
attributes to upgrade, namely Strength, Agility, and Defense. The fighting
works pretty much like rock, paper, scissors where you choose to use
one of the three attributes, and so does the monster.
- If your move counters the monster's move, your coresdponding attribute
is strengthened by 50% for the round.
- If you picked the same move as the monster, your coresdponding attribute
remains unchanged.
- If your move is countered by the monster's move, your coresdponding attribute
is weakened by 50% for the round.
Counter Relations: Strength > Agility > Defense > Strength
Eventually, you win if the attribute you picked exceeds that of the monster,
tie if you and the monster have the same corresponding attributes
you lose if you are exceeded by the monster.
You have 3 lives which is deducted by one everytime you lose, and so does the monster.
Whoever reaches 0 first loses. Your life is restored after each fight.
Try to beat as many monsters as possible.

# Features #
## Generation of random game sets and events ##
Monsters' names and attributes are randomized and constrained by the floor number, providing the player with different game experiences every time they play. Also, the tactics that the monster adopts in each combat are purely random. All of the above are implemented using the rand() function in C++.
## Data structures for storing game status
We have a self-defined character structure storing the player and monster status, including health and attributes. The monsters' names are generated in random through a list of candidate names and adjectives which are stored in two seperate lists.
## Dynamic memory management ##
The game adopts dynamic memory management in storing player and monster status as we are uncertain how long the combat will persists, hence how much memory will be needed. These memories are released after each fight for the monster and after each game for the player.
## File IO ##
There are multiple text files storing game plot, instructions, and other necessary resources.
They are read through functions in file.h and utilized in main.cpp
## Codes in multiple files ##
There are two files, one for the main game, another specifically for file input and output.
## Indentation and naming style ##
Naming style and indentation are consistent throughout the source code.
## Documentation ##
The purpose of each function is documented before the function header. 

# Compilation Instruction #
1. Download everything and put in a folder
2. cd to the folder
3. run ```make main```
4. run ```./main``` to play

The game is developed under win10, and may not be compatible with other systems or encoding formats.

# Demo Video #
https://youtu.be/5YSUgssaQOg

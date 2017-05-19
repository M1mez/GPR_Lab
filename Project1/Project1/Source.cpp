#include "robot.h"
#include "labyrinth.h"
#include <iostream>
using namespace std;



void PrintLab(string& lab);


int main() {
	string labyrinth = "";

	//blacked version of labyrinth
	string blackedMap = "";

	int width, height;
	width = height = 0;
	int entry, exit;

	labyrinth lab;

	l.ReadFile(width, height, labyrinth);
	PrintLab(labyrinth);
	CreateBlackedMap(width, height, blackedMap);
	PrintLab(blackedMap);
	width++;
	blackedMap[2 + (0 * width)] = ' ';
	blackedMap[2 + (1 * width)] = ' ';
	blackedMap[2 + (2 * width)] = ' ';
	blackedMap[3 + (2 * width)] = ' ';
	blackedMap[4 + (2 * width)] = ' ';
	blackedMap[4 + (3 * width)] = ' ';
	getentry(entry, width, labyrinth);
	PrintLab(blackedMap);

	system("PAUSE");
}



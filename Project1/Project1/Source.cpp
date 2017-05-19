#include "robot.h"
#include "labyrinth.h"
#include <iostream>
using namespace std;

int main() {
	//	string of original labyrinth
	string labString = "";

	//	blacked version of labyrinth
	string blackedMap = "";

	int width, height;
	width = height = 0;
	int entry, exit;

	Labyrinth lab;

	//	reads labyrinth from .txt file, saved in labString
	lab.ReadFile(width, height, labString);
	lab.PrintLab(labString);

	//	creates blacked version of same dimensions as labString, saved in blackedMap 	
	lab.CreateBlackedMap(width, height, blackedMap);
	lab.PrintLab(blackedMap);

	//	gets entryPoint of labString
	entry = lab.GetEntryPoint(width, labString);


	width++;
	blackedMap[2 + (0 * width)] = ' ';
	blackedMap[2 + (1 * width)] = ' ';
	blackedMap[2 + (2 * width)] = ' ';
	blackedMap[3 + (2 * width)] = ' ';
	blackedMap[4 + (2 * width)] = ' ';
	blackedMap[4 + (3 * width)] = ' ';


	lab.PrintLab(blackedMap);

	system("PAUSE");
}
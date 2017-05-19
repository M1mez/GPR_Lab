#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Labyrinth
{
public:
	Labyrinth();
	~Labyrinth();

	void ReadFile(int& width, int& height, string& labyrinth);
	void CreateBlackedMap(int& width, int& height, string& blackedMap);
	int GetEntryPoint(int& width, int& height, string& labyrinth);
	void PrintLab(int& width, int& height, string& lab);

	string labString;
};


#pragma once
#include <string>
#include <iostream>
#include <fstream>

class labyrinth
{
public:
	labyrinth();
	~labyrinth();

	void ReadFile(int& width, int& height, std::string& labyrinth);
	void CreateBlackedMap(int& width, int& height, std::string& blackedMap);
	void getentry(int& entry, int& width, std::string& labyrinth);




};


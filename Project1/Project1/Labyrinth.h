#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Labyrinth
{
private:
	void GetEntryPoint();
	void CreateBlackedMap();
	

public:
	Labyrinth();
	~Labyrinth();

	void ReadFile();
	void PrintLab(bool mapVisible);

	string m_labString;
	string m_blackMap;
	int m_entry;
	int m_exit;
	int m_width;
	int m_height;
};


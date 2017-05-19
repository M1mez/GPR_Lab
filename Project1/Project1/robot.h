#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Memory {
	Memory* right;
	Memory* straight;
	Memory* left;
};

class Robot {
public:
	Robot(string& revealed, string& black);
	virtual ~Robot();

protected:
	int startingPoint;
	string labyrinth;
	string blackMap;
};

class LeftHandAlg : public Robot {
public:
	LeftHandAlg(string& revealed, string& black);
	virtual ~LeftHandAlg();

private:
	Memory* robot_Lefty;
};

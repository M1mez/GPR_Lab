#pragma once
#include <vector>
#include "labyrinth.h"

enum Direction { NORTH, EAST, SOUTH, WEST };
using namespace std;


struct Memory {
	Memory* r; // right
	Memory* s; // straight
	Memory* l; // left
};

class Robot {
public:
	Robot(Labyrinth* lab);
	virtual ~Robot();
	void walk();
	string m_blackMap;

protected:
	void UpdateBlackMap(int pos);

	void step();
	bool check(int dir);


	Labyrinth* m_lab;
	int m_pos;
	int m_steps;
	int head;
	Memory* mem;
};

class AlgLeft : public Robot {
public:
	AlgLeft(Labyrinth* lab);
	~AlgLeft();
};

//class AlgTarry : public Robot {
//public:
//	AlgTarry();
//	virtual ~AlgTarry();
//	int go();
//};

//class Algthird : public Robot {
//public:
//	Algthird();
//	virtual ~Algthird();
//	int go();
//};


/*
bool choice(); solange keine Sackgasse => return choice(), ansonsten return false! wenn am ende, return true!

*/
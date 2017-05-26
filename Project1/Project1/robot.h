#pragma once
#include <vector>
#include "labyrinth.h"

using namespace std;


struct Memory {
	Memory* r; // right
	Memory* s; // straight
	Memory* l; // left
};

class Robot {
public:
#pragma region we will keep these >public<
	Robot(Labyrinth* lab);
	virtual ~Robot();


#pragma endregion

	void walk();
	string m_blackMap;

protected:
#pragma region we will keep these >protected<
	Labyrinth* m_lab;
	void UpdateBlackMap(int pos);
	bool check(int pos, int dir);
	int step(int pos, int dir);



#pragma endregion



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
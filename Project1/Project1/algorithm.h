#pragma once
#include "robot.h"

class Robot;

class AlgLeft : public Robot {
public:
	AlgLeft(Labyrinth* lab);
	int walk();
};


class AlgRec : public Robot {
public:
	AlgRec(Labyrinth* lab);
	bool choice();
	int walk();

};


//class AlgTarry : public Robot {
//public:
//	AlgTarry();
//	virtual ~AlgTarry();
//	int go();
//};
/*
bool choice(); solange keine Sackgasse => return choice(), ansonsten return false! wenn am ende, return true!

*/
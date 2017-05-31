#pragma once
#include <vector>
#include "labyrinth.h"

using namespace std;
class Labyrinth;

struct Memory {
	Memory *last;	// last crossing
	Memory* r;		// right
	Memory* s;		// straight
	Memory* l;		// left
	int pos;
};

class Robot {
public:
#pragma region we will keep these >public<
	Robot(Labyrinth* lab);
	virtual ~Robot();
	virtual int walk() = 0;
	void walkToCross();
	void printBlack();
	int m_steps;


#pragma endregion


protected:
#pragma region we will keep these >protected<
	Labyrinth* m_lab;
	string m_blackMap;
	Memory* mem;
	int m_pos;
	int head;
	int left;
	int straight;
	int right;

	//vector<int> m_pos;

	void UpdateBlackMap(int pos);
	bool check(int pos, int dir);
	void step(int dir);
	void align();


#pragma endregion




};


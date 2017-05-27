#pragma once
#include <vector>
#include "labyrinth.h"

using namespace std;
class Labyrinth;

struct Memory {
	Memory* r; // right
	Memory* s; // straight
	Memory* l; // left
	int pos;
};

class Robot {
public:
#pragma region we will keep these >public<
	Robot(Labyrinth* lab);
	virtual ~Robot();
	virtual int walk() = 0;
	int walkToCross(int pos, int dir);
	void printBlack();


#pragma endregion


protected:
#pragma region we will keep these >protected<
	Labyrinth* m_lab;
	string m_blackMap;
	int m_pos;
	int head;
	int m_steps;

	void UpdateBlackMap(int pos);
	bool check(int pos, int dir);
	int step(int pos, int dir);



#pragma endregion




};


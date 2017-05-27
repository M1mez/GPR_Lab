#include "robot.h"
#include <sstream>

Robot::Robot(Labyrinth* lab) : m_lab(lab)
{
	m_blackMap = lab->m_blackMap;
	m_pos = lab->m_entry;
	m_steps = 0;
	head = lab->initHead;
}
Robot::~Robot(){}

int Robot::walkToCross(int pos, int dir)
{
	
	int left = (dir + 3) % 4;
	int straight = dir;
	int right = (dir + 1) % 4;


	int ways = 0;
	if (check(pos, left))
	{
		dir = left;
		ways++;
	}
	if (check(pos, straight))
	{
		dir = straight;
		ways++;
	}
	if (check(pos, right))
	{
		dir = right;
		ways++;
	}
	m_steps++;
	UpdateBlackMap(pos);


	if (ways == 1)
	{
		step(pos, dir);
		return walkToCross(pos, dir);
	}
	else return pos;
}

void Robot::printBlack()
{
	cout << endl << m_blackMap << endl;
}


bool Robot::check(int pos, int dir)
{
	switch (dir)
	{
	case NORTH: {
		char c = m_lab->m_labString[pos - m_lab->m_width];
		if (c == ' ') return true; 
		break;
	}
	case EAST: {
		char c = m_lab->m_labString[pos + 1];
		if (c == ' ') return true;
		break;
	}
	case SOUTH: {
		char c = m_lab->m_labString[pos + m_lab->m_width];
		if (c == ' ') return true;
		break;
}
	case WEST: {
		char c = m_lab->m_labString[pos - 1];
		if (c == ' ') return true;
		break;
	}
	}
	return false;
}

int Robot::step(int pos, int dir)
{
	//bool c = onlyCheck(pos, dir);
	
	switch (dir)
	{
	case NORTH: {
		return pos - m_lab->m_width;

	}
	case EAST: {
		 return  pos + 1;
}
	case SOUTH: {
		 return pos + m_lab->m_width;

	}
	case WEST: {
		 return pos - 1;

	}
	}
	return -1;
}


void Robot::UpdateBlackMap(int pos)
{
	string& noFog = m_lab->m_labString;
	int& width = m_lab->m_width;
	int& height = m_lab->m_height;

	char* norBlPos = (!((pos - width) < 0)) ? &m_blackMap[pos - width] : nullptr;
	char* easBlPos = ((pos + 2) % width) ? &m_blackMap[pos + 1] : nullptr;
	char* souBlPos = !((pos + width)>m_blackMap.size()) ? &m_blackMap[pos + width] : nullptr;
	char* wesBlPos = (pos % width) ? &m_blackMap[pos - 1] : nullptr;

	if (norBlPos) if (*norBlPos != 'x') *norBlPos = noFog[pos - width];					// norden lab?
	if (easBlPos) if (*easBlPos != 'x') *easBlPos = noFog[pos + 1];						// osten lab?
	if (souBlPos) if (*souBlPos != 'x') *souBlPos = noFog[pos + width];					// sueden lab?
	if (wesBlPos) if (*wesBlPos != 'x') *wesBlPos = noFog[pos - 1];						// westen lab?
}



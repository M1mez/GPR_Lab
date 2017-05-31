#include "robot.h"
#include <sstream>

Robot::Robot(Labyrinth* lab) : m_lab(lab)
{
	m_blackMap = lab->m_blackMap;
	m_pos = lab->m_entry;
	m_steps = 0;
	head = lab->initHead;
	mem = new Memory;
	mem->pos = m_pos;
}
Robot::~Robot(){}

void Robot::walkToCross()
{
	int ways = 0;
	do {
		if (m_pos == m_lab->m_exit) return;
		align();
		int dir = head;

		int ways = 0;
		if (check(m_pos, left))
		{
			dir = left;
			ways++;
		}
		if (check(m_pos, straight))
		{
			dir = straight;
			ways++;
		}
		if (check(m_pos, right))
		{
			dir = right;
			ways++;
		}


		if (ways == 1)
		{
			step(dir);
			UpdateBlackMap(m_pos);
			walkToCross();
		}
	} while (ways == 1);
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

void Robot::step(int dir)
{
	head = dir;
	switch (dir)
	{
	case NORTH: {
		m_pos = m_pos - m_lab->m_width;
		break;
	}
	case EAST: {
		m_pos = m_pos + 1;
		break;
}
	case SOUTH: {
		m_pos = m_pos + m_lab->m_width;
		break;

	}
	case WEST: {
		m_pos = m_pos - 1;
		break;
	}
	}
	m_steps++;
	return;
}

void Robot::align()
{
	left = (head + 3) % 4;
	straight = head;
	right = (head + 1) % 4;
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



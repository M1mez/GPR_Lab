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

void Robot::walk()
{
	int left, straight, right;
	while (true)
	{
		//cout << m_pos << " ";
		m_pos = step(m_pos, head);
		UpdateBlackMap(m_pos);
		left = (head + 3) % 4;
		straight = head;
		right = (head + 1) % 4;
		if (m_pos == m_lab->m_exit) break;
		if (check(m_pos, left)) {	// check left
			head = left;
			continue;
		}
		if (check(m_pos, straight)) {			// check straight
			head = straight;
			continue;
		}
		if (check(m_pos, right)) {	// check right
			head = right;
			continue;
		}
		head = (head + 2) % 4;
	}
}
bool Robot::check(int pos, int dir)
{
	switch (dir)
	{
	case NORTH: {
		if (m_lab->m_labString[pos - m_lab->m_width] == ' ') return true; 
		break;
	}
	case EAST: { 
		if (m_lab->m_labString[pos + 1] == ' ') return true;
		break;
	}
	case SOUTH: {
		if (m_lab->m_labString[pos + m_lab->m_width] == ' ') return true;
		break;
}
	case WEST: {
		if (m_lab->m_labString[pos - 1] == ' ') return true;
		break;
	}
	}
	return false;
}
int Robot::step(int pos, int dir)
{
	switch (dir)
	{
		case NORTH: return pos - m_lab->m_width;
		case EAST:  return pos + 1;
		case SOUTH: return pos + m_lab->m_width;
		case WEST:  return pos - 1;
	}
	return -1;
}


void Robot::UpdateBlackMap(int pos)
{
	string& noFog = m_lab->m_labString;
	int& width = m_lab->m_width;
	int& height = m_lab->m_height;

	if (!((pos - width) < 0)) m_blackMap[pos - width] = noFog[pos - width];               // norden lab?
	if ((pos+2)%width) m_blackMap[pos + 1] = noFog[pos + 1];							  // osten lab?
	if (!((pos + width)>m_blackMap.size())) m_blackMap[pos + width] = noFog[pos + width]; // sueden lab?
	if (pos % width) m_blackMap[pos - 1] = noFog[pos - 1];
	// westen lab?
}


// ALGORITHM 1: Left Hand

AlgLeft::AlgLeft(Labyrinth* lab) : Robot(lab){}

AlgLeft::~AlgLeft(){}

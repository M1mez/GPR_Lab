#include "robot.h"
#include <sstream>




Robot::Robot(Labyrinth* lab) : m_lab(lab)
{
	m_blackMap = m_lab->m_blackMap;
	m_pos = m_lab->m_entry;
	m_steps = 0;
	if (m_pos - m_lab->m_width < 0) head = SOUTH;
	else if (!((m_pos+2) % m_lab->m_width)) head = WEST;
	else if (m_pos + m_lab->m_width > m_lab->m_labString.size()) head = NORTH;
	else if (!(m_pos % m_lab->m_width)) head = EAST;
	
	//cout << "DIRECTION: " << head << endl;
}

Robot::~Robot(){}


void Robot::walk()
{
	int left, straight, right;
	while (true)
	{
		//cout << m_pos << " ";
		step();
		left = (head + 3) % 4;
		straight = head;
		right = (head + 1) % 4;
		if (m_pos == m_lab->m_exit) break;
		if (check(left)) {	// check left
			continue;
		}
		if (check(straight)) {			// check straight
			continue;
		}
		if (check(right)) {	// check right
			continue;
		}
		head = (head + 2) % 4;
	}
}

//bool Robot::checkStraight()
//{
//	return check(head);
//}
//
//bool Robot::checkRight()
//{
//	return check((head + 1) % 4);
//}
//
//bool Robot::checkLeft()
//{
//	return check((head + 3) % 4);
//}

bool Robot::check(int dir)
{
	switch (dir)
	{
	case NORTH:
	{
		if (m_lab->m_labString[m_pos - m_lab->m_width] == ' ')
		{
			head = dir;
			return true;
		}
		break;
	}
	case EAST:
	{
		if (m_lab->m_labString[m_pos+1] == ' ')
		{
			head = dir;
			return true;
		}
		break;
	}
	case SOUTH:
	{
		if (m_lab->m_labString[m_pos + m_lab->m_width] == ' ')
		{
			head = dir;
			return true;
		}
		break;
	}
	case WEST:
	{
		if (m_lab->m_labString[m_pos - 1] == ' ')
		{
			head = dir;
			return true;
		}
		break;
	}
	}
	return false;
}


void Robot::step()
{
	int steps = 0;
	
	switch (head)
	{
		case NORTH:
		{
			m_pos -= m_lab->m_width;
			UpdateBlackMap(m_pos);
			break;
		}
		case EAST:
		{
			m_pos++;
			UpdateBlackMap(m_pos);
			break;
		}
		case SOUTH:
		{
			m_pos += m_lab->m_width;
			UpdateBlackMap(m_pos);
			break;
		}
		case WEST:
		{
			m_pos--;
			UpdateBlackMap(m_pos);
			break;
		}
	}
	m_steps++;
	UpdateBlackMap(m_pos);
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

#include "algorithm.h"



// ALGORITHM 1: Left Hand

AlgLeft::AlgLeft(Labyrinth* lab) : Robot(lab) {}


int AlgLeft::walk()
{
	int left, straight, right;
	while (true)
	{
		//cout << m_pos << " ";
		m_pos = step(m_pos, head);
		m_steps++;
		UpdateBlackMap(m_pos);
		left = (head + 3) % 4;
		straight = head;
		right = (head + 1) % 4;
		if (m_pos == m_lab->m_exit) return true;

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
	return m_steps;
}


AlgRec::AlgRec(Labyrinth* lab) : Robot(lab) {}

bool AlgRec::choice(int pos, int dir)
{
	int left = (head + 3) % 4;
	int straight = head;
	int right = (head + 1) % 4;

	bool leftC = check(pos, left);
	bool straightC = check(pos, straight);
	bool rightC = check(pos, right);

	int tmpPos = pos;
										// pos == 29
	if (leftC)
	{
		tmpPos = step(tmpPos, left);
		m_blackMap[tmpPos] = 'x';
		tmpPos = step(tmpPos, left);
		tmpPos = walkToCross(tmpPos, left);
		leftC = choice(tmpPos, left);
	}
	tmpPos = pos;
	if (straightC)
	{
		//cout << "fehler" << leftC << straightC << rightC << " " << tmpPos;
		tmpPos = step(tmpPos, straight);
		cout << tmpPos << endl;
		system("pause");
		m_blackMap[tmpPos] = 'x';
		tmpPos = step(tmpPos, straight);
		tmpPos = walkToCross(tmpPos, straight);
		straightC = choice(tmpPos, straight);
	}
	tmpPos = pos;
	if (rightC)
	{
		tmpPos = step(tmpPos, right);
		m_blackMap[tmpPos] = 'x';
		tmpPos = step(tmpPos, right);
		tmpPos = walkToCross(tmpPos, right);
		rightC = choice(tmpPos, right);
	}

	if (leftC || straightC || rightC) return true;
	else return false;
}

int AlgRec::walk()
{

	if (choice(m_pos, head))	return m_steps;
	else						return 0;
}

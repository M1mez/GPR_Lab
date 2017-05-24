#include "robot.h"

using namespace std;

int main() 
{
	int width, height;
	width = height = 0;

	Labyrinth lab;

	lab.ReadFile();			 //	ifstream



	/*blackMap[2 + (0 * lab.m_width)] = ' ';
	blackMap[2 + (1 * lab.m_width)] = ' ';
	blackMap[2 + (2 * lab.m_width)] = ' ';
	blackMap[3 + (2 * lab.m_width)] = ' ';
	blackMap[4 + (2 * lab.m_width)] = ' ';
	blackMap[4 + (3 * lab.m_width)] = ' ';*/

	//lab.PrintLab(blackedMap);

	AlgLeft *test = new AlgLeft(&lab);
	test->walk();

	lab.PrintLab(1);
	cout << test->m_blackMap;


	system("PAUSE");
}
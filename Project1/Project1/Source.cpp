#include "robot.h"

using namespace std;

int main() 
{
	int width, height;
	width = height = 0;

	Labyrinth lab;

	AlgLeft *test = new AlgLeft(&lab);
	test->walk();

	lab.PrintLab(1);
	cout << test->m_blackMap;


	system("PAUSE");
}
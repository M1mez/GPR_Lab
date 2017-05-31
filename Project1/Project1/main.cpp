#include "algorithm.h"

using namespace std;

int main() 
{
	int width, height;
	width = height = 0;

	Labyrinth lab;

	AlgLeft *test1 = new AlgLeft(&lab);
	AlgRec *test2 = new AlgRec(&lab);



	test1->walk();
	test2->walk();

	lab.PrintLab(1);
	test1->printBlack();
	cout << test1->m_steps;
	test2->printBlack();
	cout << test2->m_steps;



	system("PAUSE");
}
#include "algorithm.h"

using namespace std;

int main() 
{
	int width, height;
	width = height = 0;

	Labyrinth lab;

	//AlgLeft *test = new AlgLeft(&lab);
	AlgRec *test = new AlgRec(&lab);


	test->walk();

	lab.PrintLab(1);
	test->printBlack();


	system("PAUSE");
}
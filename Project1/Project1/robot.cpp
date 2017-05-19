#include "robot.h"
#include "labyrinth.h"
#include <sstream>


Robot::Robot(string& revealed, string& black)
{
	labyrinth = revealed;
	blackMap = black;
}


Robot::~Robot()
{

}



LeftHandAlg::LeftHandAlg(string& revealed, string& black) : Robot(revealed, black)
{
}

LeftHandAlg::~LeftHandAlg()
{
}

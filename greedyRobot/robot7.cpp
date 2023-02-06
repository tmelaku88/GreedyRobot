/*
 * robot.cpp
 *
 *  Created on: Oct 27, 2021
 *      Author: Melaku Tarekegn
 */

#include "robot7.h"

//constructor

Robot::Robot()
{
	x_initial_=0;
	y_initial_=0;
	x_target_=0;
	y_target_=0;
	max_distance=0;
}

Robot::Robot(int x1, int y1, int x2, int y2)
{

	this->x_initial_ = x1;
	this->y_initial_ =y1;
	this->x_target_ = x2;
	this->y_target_ =y2;
	max_distance=0;
}

Robot::Robot( int x1, int y1, int x2, int y2, int max_dis)
{
	this->x_initial_ = x1;
	this->y_initial_ =y1;
	this->x_target_= x2;
	this->y_target_ =y2;
	this->max_distance= max_dis;

}
//destructor
Robot::~Robot()
{

}
//getter
int Robot::get_xt() const
{

	return this-> x_target_;
}
int Robot::get_yt() const
{
	return this-> y_target_;

}
//setter
void Robot:: set_robot(int x1, int y1, int x2, int y2, int max_d)
{

	this->x_initial_ = x1;
	this->y_initial_ =y1;
	this->x_target_= x2;
	this->y_target_ =y2;
	this->max_distance= max_d;
}
//action->function

//if initial and target coordinates are equal returns current paths, else
// if initial and target coordinates are not equal passes all parameters to get FindPaths()
// but the robot never move in the same direction more than MaxDistance times in a row

void Robot:: FindPaths(int xi, int yi, char initial, int move, string current_path)
{
    if(move > max_distance)
    	return;

    // Base case
    if(xi == x_target_ && yi == y_target_)
    {
    	direction.push_back(current_path);
        return;
    }
    // recursive case

    //stimulate and then get North movement of the robot
    if(y_target_ > yi)
    {
        if(initial == 'N')
        	FindPaths(xi, yi + 1, 'N', move + 1, current_path + 'N');
        else
        	FindPaths(xi, yi + 1, 'N', 1, current_path + 'N');
    }
    //stimulate and then get South movement of  the robot
    else if(y_target_ < yi)
    {
        if(initial == 'S')
        	FindPaths(xi, yi - 1, 'S', move + 1, current_path + 'S');
        else
        	FindPaths(xi, yi - 1, 'S', 1, current_path + 'S');
    }

    //stimulate and then get East movement of the robot
    if(x_target_ > xi)
    {
        if(initial == 'E')
        	FindPaths(xi + 1, yi, 'E', move + 1, current_path + 'E');
        else
        	FindPaths(xi + 1, yi, 'E', 1, current_path + 'E');
    }
    //stimulate and then get West movement of the robot
    else if (x_target_ < xi)
    {
        if(initial == 'W')
        	FindPaths(xi - 1, yi, 'W', move + 1, current_path + 'W');
        else
        	FindPaths(xi - 1, yi, 'W', 1, current_path + 'W');
    }
}

//operator overloading
ostream& operator<<(ostream &stream, const Robot &robot)
{


stream << "Number of paths: " << direction.size() << endl;

    for (int i=0; i<direction.size();i++)
    {
		stream<<direction[i]<<endl;
	}

	return stream;

}






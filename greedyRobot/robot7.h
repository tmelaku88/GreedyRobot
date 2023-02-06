/*
 * robot.h
 *
 *  Created on: Oct 27, 2021
 *      Author: Melaku Tarekegn
 */

#ifndef ROBOT7_H_
#define ROBOT7_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;

static vector<string> direction;
class Robot
{
public:

	//constructor
	Robot();
	Robot(int x1, int y1, int x2, int y2);
	Robot( int x1, int y1, int x2, int y2, int max_dis);

	//destructor
	~Robot();

	//getter-setter
	int get_xt() const;
    int get_yt() const;
    void set_robot(int x1, int y1, int x2, int y2, int max_d);

	//Operator overloading
	friend ostream& operator<<(ostream& stream, const Robot& rb);

	//Action
	void FindPaths(int xi, int yi, char initial, int move, string current_path);
	// public data members
	int x_initial_;
	int y_initial_;
	int max_distance;


private:
	//private data members
	int x_target_;
	int y_target_;

};

#endif /* ROBOT7_H_ */

/*
 * greedy_robot.cpp
 *
 *  Created on: Oct 27, 2021
 *      Author: Melaku Tarekegn
 */

#include "robot7.h"
using namespace std;

//main method
int main(int argc, char*argv[])
{
		int x1;
		int y1;
	    int x2;
		int y2;
		int max_distance;


		for(int i=0; i<argc;i++)
		{
			if(argc>=1)
			{
				 x1=atoi(argv[1]);
				 y1=atoi(argv[2]);
			     x2=atoi(argv[3]);
			     y2=atoi(argv[4]);
				 max_distance=atoi(argv[5]);
			}
		}

		Robot rb(x1, y1, x2, y2, max_distance);
		string path=" ";
		rb.FindPaths(x1, y1,'r', 0, path);
		cout << rb << endl;


	    returntfikr11@wmj
		 0;
	}













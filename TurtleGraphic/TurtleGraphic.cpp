// TurtleGraphic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void drawFloor(int a[][20]);
void moveTurtle(int tp, int pp, int move, int floor[][20], int turtle[][20]);

int _tmain(int argc, _TCHAR* argv[])
{
	enum turtlePosition {UP, DOWN, LEFT, RIGHT};
	enum penPosition {PENUP, PENDOWN};
	turtlePosition tp = RIGHT;
	penPosition pp = PENUP;
	string pen = "Up";
	string turt = "Right";
	int floor[20][20] = {0};
	int turtlePos[20][20] = {1};
	int command = 0;
	int xtra = 0;

	while(command != 9)
	{
		cout << endl;
		for(int i = 0; i < 20; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				if(1 == turtlePos[i][j]){cout << "The turtle is currently at position " << i << ", " << j << endl;}
			}
		}
		if(UP == tp){turt = "Up";}
		if(DOWN == tp){turt = "Down";}
		if(LEFT == tp){turt = "Left";}
		if(RIGHT == tp){turt = "Right";}
		if(PENDOWN == pp){pen = "Down";}
		if(PENUP == pp){pen = "Up";}

		cout << "The turtle is currently facing " << turt << endl;
		cout << "The pen is currently " << pen << endl;

		cout << "Please enter a command" << endl;
		cout << "\t1. Pen up" << endl;
		cout << "\t2. Pen down" << endl;
		cout << "\t3. Turn right" << endl;
		cout << "\t4. Turn left" << endl;
		cout << "\t5. Move forward" << endl;
		cout << "\t6. Print the floor" << endl;
		cout << "\t9. Quit" << endl;
		cin >> command;

		switch(command)
		{
			case 1:
				pp = PENUP;
				break;
			case 2:
				pp = PENDOWN;
				break;
			case 3:
				if(RIGHT == tp){tp = DOWN;}
				else if(DOWN == tp){tp = LEFT;}
				else if(LEFT == tp){tp = UP;}
				else if(UP == tp){tp = RIGHT;}
				break;
			case 4:
				if(RIGHT == tp){tp = UP;}
				else if(UP == tp){tp = LEFT;}
				else if(LEFT == tp){tp = DOWN;}
				else if(DOWN == tp){tp = RIGHT;}
				break;
			case 5:
				cout << "How many steps would you like to move forward? ";
				cin >> xtra;
				moveTurtle(static_cast<int>(tp), static_cast<int>(pp), xtra, floor, turtlePos);
				break;
			case 6:
				drawFloor(floor);
				break;
			case 9:
				break;
		}
				
	}
		

	return 0;
}

void drawFloor(int a[][20])
{
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(1 == a[i][j])
			{
				cout << setw(2) << "[*]";
			}
			else{cout << setw(2) << "[ ]";}
		}
		cout << endl;
	}

}

void moveTurtle(int tp, int pp, int move, int floor[][20], int turtle[][20])
{
	int turtPositionX = 0;
	int turtPositionY = 0;

	//find the turtle's current position
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(1 == turtle[i][j]){turtPositionX = i; turtPositionY = j;}
		}
	}

	//turtle facing right, pen up
	if(3 == tp && 0 == pp)
	{
		if(turtPositionY + move < 20){turtle[turtPositionX][turtPositionY + move] = 1; turtle[turtPositionX][turtPositionY] = 0;}
		else{cout << "You cannot make that move. Try again" << endl;}
	}
	//turtle facing right, pen down
	if(3 == tp && 1 == pp)
	{
		if(turtPositionY + move < 20)
		{
			turtle[turtPositionX][turtPositionY + move] = 1; 
			turtle[turtPositionX][turtPositionY] = 0;

			for(int i = turtPositionX; i <= turtPositionX; i++)
			{
				for(int j = turtPositionY+1; j <= turtPositionY+move; j++)
				{
					floor[i][j] = 1;
				}
			}
		}
		else{cout << "You cannot make that move. Try again" << endl;}
	}

	//turtle facing down, pen up
	if(1 == tp && 0 == pp)
	{
		if(turtPositionX + move < 20){turtle[turtPositionX+move][turtPositionY] = 1; turtle[turtPositionX][turtPositionY] = 0;}
		else{cout << "You cannot make that move. Try again" << endl;}
	}
	//turtle facing down, pen down
	if(1 == tp && 1 == pp)
	{
		if(turtPositionX + move < 20)
		{
			turtle[turtPositionX+move][turtPositionY] = 1; 
			turtle[turtPositionX][turtPositionY] = 0;

			for(int i = turtPositionX+1; i <= turtPositionX+move; i++)
			{
				for(int j = turtPositionY; j <= turtPositionY; j++)
				{
					floor[i][j] = 1;
				}
			}
		}
		else{cout << "You cannot make that move. Try again" << endl;}
	}

	//turtle facing left, pen up
	if(2 == tp && 0 == pp)
	{
		if(turtPositionY - move > 0){turtle[turtPositionX][turtPositionY-move] = 1; turtle[turtPositionX][turtPositionY] = 0;}
		else{cout << "You cannot make that move. Try again" << endl;}
	}
	//turtle facing left, pen down
	if(2 == tp && 1 == pp)
	{
		if(turtPositionY - move > 0)
		{
			turtle[turtPositionX][turtPositionY-move] = 1; 
			turtle[turtPositionX][turtPositionY] = 0;

			for(int i = turtPositionX; i <= turtPositionX; i++)
			{
				for(int j = turtPositionY-move; j <= turtPositionY-1; j++)
				{
					floor[i][j] = 1;
				}
			}
		}
		else{cout << "You cannot make that move. Try again" << endl;}
	}

	//turtle facing up, pen up
	if(0 == tp && 0 == pp)
	{
		if(turtPositionX - move > 0){turtle[turtPositionX-move][turtPositionY] = 1; turtle[turtPositionX][turtPositionY] = 0;}
		else{cout << "You cannot make that move. Try again" << endl;}
	}
	//turtle facing up, pen down
	if(0 == tp && 1 == pp)
	{
		if(turtPositionX - move > 0)
		{
			turtle[turtPositionX-move][turtPositionY] = 1; 
			turtle[turtPositionX][turtPositionY] = 0;

			for(int i = turtPositionX-move; i <= turtPositionX-1; i++)
			{
				for(int j = turtPositionY; j <= turtPositionY; j++)
				{
					floor[i][j] = 1;
				}
			}
		}
		else{cout << "You cannot make that move. Try again" << endl;}
	}

}


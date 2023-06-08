//Cheung Ka Yan,1155162671,1155162671@link.cuhk.edu.hk
#include <iostream>
#include "KnightsPath.h"
#include <stdio.h>      
using namespace std;

//Returns the number of steps the knight has walked
int KnightsPath::getSteps()const
{
	//int steps;
	return steps;
}

//Prints out the drunk knight’s path 
void KnightsPath::print()const
{
	//  A B C D E F
	//0 . . . . . .
	//1 . . . . . .
	//2 . . . . . .
	//3 . . . . . .
	//4 . . . . . .
	//5 . . . . . .
	cout << "     ";
	for (int ASCII_count = 0; ASCII_count < N; ASCII_count++)
	{
		cout << char(ASCII_count + 65);
		cout << " ";
	}
	cout << endl;
	for (int counter = 0; counter < N; counter++)
	{
		for (int y = 0; y < N; y++)
		{
			cout << "  ";
			cout << counter;
			cout << "  ";
			if (board[counter][y] == 0)
			{
				cout << "k";
				cout << "  ";
			}
			else if (y == currentC && counter == currentR)
			{
				cout << "K";
				cout << "  ";
			}
			else if (board[counter][y] == -1)
			{
				cout << ".";
				cout << "  ";
			}
			else
			{
				cout << board[counter][y];
				cout << "  ";
			}
		}
		cout << endl;
	}
	//Print out the steps
	cout << "Steps: ";
	cout << steps;
	cout << endl;
}

//Creates a drunk knight’s path where the knight is initially positioned at row r, column c
KnightsPath::KnightsPath(int r, int c) 
{
	currentC = c;//temp store
	currentR = r;//temp store
	for (int counter = 0; counter < N; counter++) 
	{
		for (int y = 0; y < N; y++) 
		{
			if (y == c && counter == r)
			{
				board[counter][y] = 0;
				//continue;
			}
			board[counter][y] = -1;
		}
		//Make the back steps
		steps = 0;
		previousR = -1;
		previousC = -1;
	}
}

//Checks whether the knight in the path can be moved from the current position 
bool KnightsPath::isValid(int r, int c)const
{
	bool flag = false;//Default to be false
	if (board[r][c] != -1)//Make all place to be able to move in
	{
		flag = false;
	}
	if ((r > N - 1 || r < 0) || (c > N - 1 || c < 0)) 
	{
		flag = false;
		cout << "abc";
	}
	
	//Watch the move
	if ((r == currentR + 2 && c == currentC - 1) || (r == currentR + 1 && c == currentC + 2) || (r == currentR - 1 && c == currentC + 2) || (r == currentR - 2 && c == currentC - 1) || (r == currentR - 2 && c == currentC + 1) || (r == currentR + 2 && c == currentC + 1) || (r == currentR - 1 && c == currentC - 2) || (r == currentR + 1 && c == currentC - 2))
	{
		if (steps != 0) 
		{
			if (((previousC - currentC) * (c - currentC) + (currentR - previousR) * (currentR - r)) > 0)
			{
				flag = false;
			}
			else
			{ 
				flag = true;
			}
		}
		else
		{
			flag = true;
		}
	}
	else 
	{
		flag = true;
	}
	return flag;
}

//Checks whether the knight has more possible moves to make
bool KnightsPath::hasMoreMoves()const 
{
	bool flag = true;//Default to be true
	for (int counter = 0; counter < N; counter++) 
	{
		for (int y = 0; y < N; y++) 
		{
			if (isValid(counter, y) == true) 
			{
				flag = true;
			}
		}
	}
	return flag;
}

//Tries to move the knight from its current position to the destination at row r, column c
bool KnightsPath::move(int r, int c) 
{
	bool flag = false;//Default to be false
	previousC = currentC;
	currentC = c;
	previousR = currentR;
	currentR = r;
	if (isValid(r, c) == true) 
	{
		flag = true;
		steps = steps + 1;
		board[currentR][currentC] = steps;
	}
	else 
	{
		flag = false;
	}
	return flag;
}

//int main() 
//{
	
//}
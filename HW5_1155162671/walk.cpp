//Cheung Ka Yan,1155162671,1155162671@link.cuhk.edu.hk
#include <iostream>
#include "KnightsPath.h"
#include <stdio.h>      
using namespace std;

int main()
{
	int row, int_c; //Int r and c
	char char_col;
	const int N = 6;// Default to be 6x6 box
	while (1) 
	{
		//Start the game
		cout << "Enter starting position (col row) :";
		cin >> char_col;
		cin >> row;
		int_c = char_col - 'A';
		if ((int_c < 0 || int_c > N - 1) || (row < 0 || row > N - 1))
		{
			cout << "Invalid. Try again!";
			cout << endl;
		}
		else 
		{
			break;
		}
	}
	//Onces end the loop break then cal the path
	KnightsPath foh(row , int_c);
	//And print the board out
	foh.print();

	//Move the hourse
	while (1) 
	{
		cout << "Move the knight (col row): ";
		cin >> char_col;
		cin >> row;
		int_c = char_col - 'A';
		//Cannot move
		if (foh.isValid(row, int_c) = true)
		{
			foh.move(row, int_c);
			foh.getSteps();
			//Returns the number of steps the knight has walked
		}
		//Can move
		if (foh.isValid(row, int_c) = false)
		{
			cout << "Invalid. Try again!";
			cout << endl;
		}
		//If there are no more steps to be move
		if (foh.hasMoreMoves() == false)
		{
			//Print the NxN board
			foh.print();
			cout << "Finished! No more moves!";
			cout << endl;
			cout << "Still drunk ? Walk wiser!";
			break;
		}
		//If there are more steps can be move
		if (foh.hasMoreMoves() == true)
		{
			//Print the NxN board
			foh.print(); 
		}
		
	}
}
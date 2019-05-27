//File: App.cpp

//Name:Islam Osama Nwishy
//ID#: 900170200
//Assignment 1 - Part (1)

#include <iostream>
#include "Stackt.h"
#include "Stackt.cpp"
using namespace std;


int Start();
void TowersOfHanoi(int N, StackT<int> &Source, StackT<int> &Target, StackT<int> &Aux, int&moves);
void Update(int N, StackT<int> &Source, StackT<int> &Target, StackT<int> &Aux, int&moves);
void FindAndDisplay(char Name, StackT<int> &Source, StackT<int> &Target, StackT<int> &Aux);

//Starts the program and asks if you want to restart
void main() {
	//Restart returns true only if the user enters Y or y when asked
	//choice is made to take the users input for the answer if they want to restart the program or not
	bool Restart = false;
	char choice;

	do {
		cout <<endl<< Start() << " Moves Were Made" << endl;
		cout <<endl <<endl<<"Do you want to Restart?" << endl << "Y or N ?" << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
			Restart = true;
		else
			Restart = false;
	} while (Restart);
	

}


//The program's Entry point
//Takes the number of disks from the user and calls other functions to solve the puzzle
//Returns the number of moves made
int Start() {
	//N for the number of disks in the puzzle
	//moves for the number of moves to be made to solve the puzzle (the value Start() returns)
	int N, Moves = 0;

	//Input
	cout << "Please Enter The Number of Disks" << endl;
	cin >> N;
	cout << endl;


	//Declartion of stacks (Rods)
	StackT<int> RodA(N, 'A');
	StackT<int> RodB(N, 'B');
	StackT<int> RodC(N, 'C');

	//Placing of Disks on the first Rod
	for (int Disk = N; Disk > 0; Disk--)
	{
		RodA.Push(Disk);
	}

	//Solve the puzzle
	TowersOfHanoi(N, RodA, RodC, RodB, Moves);

	//return the number of moves
	return Moves;
}

//The Recursive Function made to solve the Puzzle
void TowersOfHanoi(int N, StackT<int> &Source, StackT<int> &Target, StackT<int> &Aux, int&moves) {

	if (N == 1) {
		//Move Disk 1 to Target Directly
		//Update
		Update(N, Source, Target, Aux, moves);
		return;
	}
	else {
		//Call Towers of Hanoi for N-1 Disks to move from source to Aux
		TowersOfHanoi(N - 1, Source, Aux, Target, moves);
		//Update
		Update(N, Source, Target, Aux, moves);
		//Call Towers of Hanoi for N-1 Disks to move from Aux to Target
		TowersOfHanoi(N - 1, Aux, Target, Source, moves);
	}

}

//Shows Every Move
void Update(int N, StackT<int> &Source, StackT<int> &Target, StackT<int> &Aux, int&moves) {

	//Show the move and add it to the variable moves
	cout << "Move Disk " << N << " from " << Source.Name << " To " << Target.Name << endl;
	moves++;

	//Move a disk
	int Disk;
	Source.Pop(Disk);
	Target.Push(Disk);

	//Display the 3 Rods
	FindAndDisplay('A', Source, Target, Aux);
	FindAndDisplay('B', Source, Target, Aux);
	FindAndDisplay('C', Source, Target, Aux);
	cout << "----------------------------------------" << endl;
	
}


//Finds the Stack With name "Name" and Displays it
//P.S. I Tried to make it with a loop but it throwed me a weird Error
void FindAndDisplay(char Name,StackT<int> &Source, StackT<int> &Target, StackT<int> &Aux) {
	if (Source.Name == Name) {
		cout << endl << "Tower " << Name << ": ";
		Source.Display();
		cout << endl;

	}
	else if (Target.Name == Name) {
		cout << endl << "Tower " << Name << ": ";
		Target.Display();
		cout << endl;
	}
	else {
		cout << endl << "Tower " << Name << ": ";
		Aux.Display();
		cout << endl;
	}
	
}
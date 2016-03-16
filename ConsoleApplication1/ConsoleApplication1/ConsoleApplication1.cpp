// Assignment 3 - Chapter 11's "Inventory Bins" assignment
// The goal of this assignment is to utilize data structures to simulate "inventory bins" capable of carrying up to 30 units of a given item. 
// The structure of the "inventory bins" should hold the # of units in the bin as well as a description of the contents. 

// Declare header files.
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string> 
#include <cctype>
using namespace std;

// Declare constant integer for the size of the array to be declared. 
const int Bin_count = 10;

// Declare the Inventory_Bin data structure
struct Inventory_Bin
{
	string description; //Item description
	int num;			// Number of parts in the bin
};

// Declare Function Prototypes
void Bin_Select(Inventory_Bin [], int);
void Parts_Add(Inventory_Bin&, int);
void Parts_Remove(Inventory_Bin&, int);

int main()
{
	// Declare character variable to enable repetition of the program.
	char Again = 'y';
	
	// Declare variable to store menu selection.
	int choice;

	// Declare Array of Inventory_Bins
	Inventory_Bin bins[Bin_count] = {
		{"Valve", 10},
		{"Bearing", 5},
		{"Bushing", 15},
		{"Coupling", 21},
		{"Flange", 7},
		{"Gear", 5},
		{"Gear Housing", 5},
		{"Vacuum Gripper", 25},
		{"Cable", 18},
		{"Rod", 12}
	};

	do
	{
		// Display bin contents as a menu.
		for (int count = 0; count < 10; count++)
		{
			cout << "Bin #" << setw(3) << (count+1);
			cout << ", Part: " << bins[count].description;
			cout << ", Quantity: " << bins[count].num << endl;
		}

		// Query the user to select a bin.
		cout << "\nChoose a bin Number (Enter 0 if you wish to quit):\n>>>>>  ";
		cin >> choice;

		// Validate user input.
		while(choice < 0 || choice > Bin_count)
		{
			cout << "\nI'm sorry. That was not a valid input.\n";
			cout << "\nChoose a bin Number (Enter 0 if you wish to quit):\n>>>>>  ";
			cin >> choice;
		}

		// Call "Bin_Select" function unless choice entered == 0.
		if(choice == 0)
			Again = 'n';
		else
			Bin_Select(bins, choice - 1);
		// Query the user to see if they would like to repeat the program. 
		cout << "\n\nWell, that was fun.\nWould you like to run the program again? (enter 'y' for 'yes' and any other input for 'no')\n\n>>>>>>   ";
		cin >> Again;
		// Clear the console if they wish to repeat the program. 
		if (tolower(Again) == 'y')
			system("cls");
	// Close the while loop. 
	}while(tolower(Again)=='y');
	

	return 0;
}

void Bin_Select(Inventory_Bin b[], int choice)
{
	int Partscount; // # of parts
	char addrem;	// Addition or Removal 

	// Query the user as to which action they would like to take. 
	cout << "Would you like to register the addition or removal of inventory?\n(Please enter 'A' for addition and 'R' for removal)\n\n>>>>>     ";
	cin >> addrem;

	// Input validation.
	while (toupper(addrem) != 'A' && toupper(addrem) != 'R')
	{
		cout << "I'm sorry. That input was not valid." << endl;
		cout << "Would you like to register the addition or removal of inventory?\n(Please enter 'A' for addition and 'R' for removal)\n\n>>>>>     ";
		cin >> addrem;
	}

	// Process user selection.
	if (toupper(addrem) == 'A')
	{
		// Get the size of the inventory increase.
		cout << "How large of an increase in inventory would you like to register?\n\n>>>>> ";
		cin >> Partscount;

		// Pass Partscount to "Parts_Add" function. 
		Parts_Add(b[choice], Partscount);
	}
	else
	{
		// Get the size of the inventory reduction.
		cout << "How large of a reduction in inventory would you like to register?\n\n>>>>>  ";
		cin >> Partscount;

		// Pass Partscount to the "Parts_Remove" function. 
		Parts_Remove(b[choice], Partscount);
	}
}

// Define "Parts_Add" function. 
void Parts_Add(Inventory_Bin &bin, int Partscount)
{
	// Validate the input. 
	if (Partscount < 0)
		cout << "\nError: You must use positive whole numbers.\n";
	else if (Partscount + bin.num > 30)
		cout << "\nError: That amount would exceed maximum inventory.";
	// Increase inventory by specified amount if validation passes.
	else
		bin.num += Partscount;
}

void Parts_Remove(Inventory_Bin &bin, int Partscount)
{
	// Validate the input.
	if (Partscount < 0)
		cout << "\nError: You must use positive whole numbers.\n";
	else if (bin.num - Partscount < 0)
		cout << "\nError: You are removing more parts than you have in\ninventory.";
	// Remove the designated # if validation passes. 
	else
		bin.num -= Partscount;
}
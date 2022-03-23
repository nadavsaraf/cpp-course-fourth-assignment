#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// task 1 functions

double large_of_average(double a[], int size)
{
	double average = 0; // calculates the average of the series
	double sum = 0; // calculates the sum of the series
	double num_of_big_average = 0; // counts the numbers that are bigger than the average
	for (int i = 0; i < size; i++)
	{
		sum = sum + a[i];
	}
	average = sum / size;
	for (int i = 0; i < size; i++)
	{
		if (a[i] > average)
		{
			num_of_big_average++;
		}
	}
	return (num_of_big_average / size) * 100;
}

// task 2 functions

bool is_diff(double a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (a[i] == a[j])
			{
				return false;
			}
		}
	}
	return true;
}

// task 3 functions

const int COLS = 8; // present the colums in the game
const int ROWS = 8; // present the rows in the game
void getchar_mat(char mat[][COLS])
{
	srand(time(0));
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			mat[i][j] = rand() % 2;
			if (mat[i][j] == 0)
			{
				mat[i][j] = '*';
			}
			else
			{
				mat[i][j] = '.';
			}
		}
	}
}

void printchar_mat(char mat[][COLS], int i, int j)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << setw(5) << mat[i][j];
		}
		cout << endl;
	}
}

bool is_in(char mat[][COLS], int i, int j)
{
	if (i >= 0 && i < ROWS && j >= 0 && j < COLS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int num_of_neighbors(char mat[][COLS], int i, int j)
{
	if (is_in(mat, i, j))
	{
		int count = 0;
		for (int a = i - 1; a <= i + 1; a++)
		{
			for (int b = j - 1; b <= j + 1; b++)
			{
				if (a >= 0 && a < ROWS && b >= 0 && b < COLS)
				{
					if (a == i && b == j)
					{
						continue;
					}
					if (mat[a][b] == '*')
					{
						count++;
					}
				}
			}
		}
		return count;
	}
}

void Game(char mat[][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (mat[i][j] == '.')
			{
				mat[i][j] = num_of_neighbors(mat, i, j) + 48;
			}
			cout << setw(5) << mat[i][j];
		}
		cout << "\n";
	}
}




int main()
{
	// this program present the menu of the task, the program reads the user's selection and
	// sends it to the selected task

	int task_number; // the number of task that the user select
	cout << "menu: \n";
	cout << "\n";
	cout << "0. exit \n";
	cout << "1. For large of average \n";
	cout << "2. For test if  all numbers in array are different \n";
	cout << "3. For Game  MinesWeeper \n";
	cout << "please select the number of task you want to check \n";
	cin >> task_number;

	while (task_number != 0)
	{
		switch (task_number)
		{

		case 1:
		{

			// this program receives an array of real numbers, the program will print the 
			// percentage of numbers is the array that are bigger than the average

			int size1;
			double a1[100];
			cout << "enter size of the array up to 10" << endl;
			cin >> size1;
			for (int i = 0; i < size1; i = i++)
			{
				cout << "enter " << i << "th value" << endl;
				cin >> a1[i];
			}
			cout << large_of_average(a1, size1) << "% of the numbers in the array are bigger than the average \n";

			break;
		}

		case 2:
		{

			// This program gets an array and its size the program will print true if all the numbers
			//in the array are different from each other, and print false if not

			int size2;
			double a2[100];
			cout << "enter size of the array up to 10" << endl;
			cin >> size2;
			for (int i = 0; i < size2; i = i++)
			{
				cout << "enter " << i << "th value" << endl;
				cin >> a2[i];
			}
			cout << "are the numbers in the array are diffrent from each other? \n ";
			if (is_diff(a2, size2))
			{
				cout << "true" << endl;
			}
			else
			{
				cout << "false" << endl;
			}

			break;
		}

		case 3:
		{
			// this program present the game Mines Weeper

			char mat[ROWS][COLS];
			cout << "\n";
			getchar_mat(mat);
			cout << "THIS IS YOUR GAME !!! \n";
			printchar_mat(mat, ROWS, COLS);
			cout << "\n";
			cout << "\n";
			Game(mat);

			break;
		}
		}
		cout << "menu: \n";
		cout << "\n";
		cout << "0. exit \n";
		cout << "1. For large of average \n";
		cout << "2. For test if  all numbers in array are different \n";
		cout << "3. For Game  MinesWeeper \n";
		cout << "please select the number of task you want to check \n";
		cin >> task_number;

	}
	cout << "thank you and goodbye";

	return 0;
}
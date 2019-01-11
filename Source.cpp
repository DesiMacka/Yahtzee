/* This program uses a set and a multiset data structure
	to display a result for the completion of a 
	yahtzee game.
	
	Written by Desi, CIS 2542
	05/12/17
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <string>

using namespace std;

int main()
{

	cout << "Welcome to Yahtzee!" << endl;
	cout << "Enter five dice values (from 1 to 6) to see your result" << endl;

	//Input values
	int first, second, third, fourth, fifth;
	cin >> first;
	cin >> second;
	cin >> third;
	cin >> fourth;
	cin >> fifth;

	//Asserts to make sure the dice value ranges from 1-6
	assert(first <= 6 && first >= 1);
	assert(second <= 6 && second >= 1);
	assert(third <= 6 && third >= 1);
	assert(fourth <= 6 && fourth >= 1);
	assert(fifth <= 6 && fifth >= 1);

	// Insert the values in a set and multiset
	set<int> dices = { first, second, third, fourth, fifth };
	multiset<int> multidices = { first, second, third, fourth, fifth };


	if (dices.size() == 5)
	{
		//Check for a large straight
		if ((*(dices.begin()) != 1) || (*(dices.rbegin()) != 6))
		{
			cout << "Large Straight" << endl;
		}
		//Check for a small straight
		else if (((*next(dices.begin(), 1)) == 3) || ((*next(dices.begin(), 3)) == 4))
		{
			cout << "Small straight" << endl;
		}

		else
		{
			cout << "OUT OF LUCK" << endl;
		}
	}

	if (dices.size() == 4)
	{
		//Check for a small straight
		if (((*dices.begin() == 1) && (*dices.rbegin() == 4)) ||
			((*dices.begin() == 2) && (*dices.rbegin() == 5)) ||
			((*dices.begin() == 3) && (*dices.rbegin() == 6)))

		{
			cout << "Small Straight" << endl;
		}

		else 
		{
			cout << "OUT OF LUCK" << endl;
		}
	}

	else if (dices.size() == 3)
	{
		// Check for 3 of a kind
		if ((*next(multidices.begin(), 0) == *next(multidices.begin(), 2)) ||
			(*next(multidices.begin(), 2) == *next(multidices.begin(), 4)) ||
			(*next(multidices.begin(), 1) == *next(multidices.begin(), 3)))

		{
			 cout << "3 of a Kind" << endl;
		}

		else
		{
			cout << "OUT OF LUCK" << endl;
		}
	}

	else if (dices.size() == 2)
	{
		//Check for a full-house
		if ((*next(multidices.begin(), 0) != *next(multidices.rbegin(), 1)) ||
			(*next(multidices.begin(), 3) != *next(multidices.rbegin(), 4)))
		{
			cout << "Full-House" << endl;
		}

		//Every other case of a size of (2) is a 4 of a kind
		else 
		{
			cout << "4 of a Kind" << endl;
		}
	}

	//Check for Yahtzee!
	else if (dices.size() == 1)
	{
		cout << "YAHTZEE!" << endl;
	}


	system("pause");
	return 0;
}
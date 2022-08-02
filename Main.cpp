#include <iostream>
#include <string>

void Pathfinder();

int main()
{
    Pathfinder();
}


void Pathfinder()
{
	int arrayValues[16];			// aa, ab, ac, ad, ba, bb, bc, bd, ca, cb, cc, cd, da, db, dc, dd 
	int xNum = 0; 					// 0 = a source, 1 = b source, 2 = c source, 3 = d source
	int yNum = 0; 					// 0 = a destination, 1 = b destination, 2 = c destination, 3 = d destination
									// xNum + (yNum * 4) = source + destination

	std::string input;				// Initializing variables
	std::string x;
	std::string y;
	std::string cost;
	int distance = 0;

	for (int i = 0; i < 16; i++)	// Filling the Array with 999s
	{
		arrayValues[i] = 999;
	}

	std::cout << "Input two points (among a, b, c, d) followed by the cost (from 1 to 9) between them. \n";
	std::cout << "Example: (a, b, 5) \n";
	std::cout << "Please do this 4 times: \n\n";

	for (int i = 0; i < 4; i++)
	{
		getline(std::cin, input);
		x = input.substr(1, 1);
		y = input.substr(4, 1);
		cost = input.substr(7, 1);
		distance = stoi(cost);						// Turning cost into an integer

		if (x == "a")
		{
			xNum = 0;
		}
		if (x == "b")
		{
			xNum = 1;
		}
		if (x == "c")
		{
			xNum = 2;
		}
		if (x == "d")
		{
			xNum = 3;
		}
		if (y == "a")
		{
			yNum = 0;
		}
		if (y == "b")
		{
			yNum = 1;
		}
		if (y == "c")
		{
			yNum = 2;
		}
		if (y == "d")
		{
			yNum = 3;
		}

		arrayValues[yNum + (xNum * 4)] = distance;
		arrayValues[xNum + (yNum * 4)] = distance;
	}

	std::cout << "\nInput two points (among a, b, c, d) to calculate the distance between them.\n";
	std::cout << "Example: (a, b) \n\n";
	getline(std::cin, input);
	x = input.substr(1, 1);
	y = input.substr(4, 1);

	if (x == "a")
	{
		xNum = 0;
	}
	if (x == "b")
	{
		xNum = 1;
	}
	if (x == "c")
	{
		xNum = 2;
	}
	if (x == "d")
	{
		xNum = 3;
	}
	if (y == "a")
	{
		yNum = 0;
	}
	if (y == "b")
	{
		yNum = 1;
	}
	if (y == "c")
	{
		yNum = 2;
	}
	if (y == "d")
	{
		yNum = 3;
	}

	int currentCost = 0;
	int cheapestCost = 999;
	int path[4] = { xNum, 4, 4, 4 };			// Optimal path

	// 1 Step Solution Done

	currentCost = arrayValues[xNum + (yNum * 4)];
	if (currentCost < cheapestCost)
	{
		cheapestCost = currentCost;
		path[1] = yNum;
	}
	std::cout << "\nDistance from: " << xNum << " to " << yNum << " is: " << currentCost;


	// 2 Step Solution Done

	for (int i = 0; i < 16; i++)
	{
		std::cout << "\nValue " << i << " = " << arrayValues[i];
	}

	int firstHalf = 0;
	int secondHalf = 0;


	for (int a = 0; a < 4; a++)					// i Cycles through Midpoints a through d
	{
		firstHalf = arrayValues[xNum + (a * 4)];
		secondHalf = arrayValues[yNum + (a * 4)];
		currentCost = firstHalf + secondHalf;
		if (currentCost < cheapestCost)
		{
			cheapestCost = currentCost;
			path[1] = a;
			path[2] = yNum;
		}
		
		std::cout << "\nDistance from: " << xNum << " to " << a << " is: " << firstHalf;
		std::cout << "\nDistance from: " << a << " to " << yNum << " is: " << secondHalf;
	}


	//// 3 Step Solution -- Still Working on it will submit for 3rd Challenge

	//int stop1 = 4;
	//int stop2 = 4;

	//for (int b = 0; b < 4; b++)		// cycles from a b c d
	//{
	//	if (xNum != b) && (yNum != b) && (stop1 != b))		// if first and second and last aren't
	//	{													// then assign to second
	//		stop1 = b;
	//	}
	//	else if ((xNum != b) && (yNum != b)) 				// otherwise if first and last aren't
	//	{													// then assign to third
	//		stop2 = b;
	//	}
	//}

	//int cost1 = arrayValues[xNum + (stop1 * 4)];
	//int cost2 = arrayValues[stop1 + (stop2 * 4)];
	//int cost3 = arrayValues[stop2 + (yNum * 4)];
	//currentCost = cost1 + cost2 + cost3;
	// 
	//if (currentCost < cheapestCost)
	//{
	//	cheapestCost = currentCost;
	//}
	//
	//std::cout << "\nDistance from: " << xNum << " to " << stop1 << " is: " << cost1;
	//std::cout << "\nDistance from: " << stop1 << " to " << stop2 << " is: " << cost2;
	//std::cout << "\nDistance from: " << stop2 << " to " << yNum << " is: " << cost3;
	//
	//int cost4 = arrayValues[xNum + (stop2 * 4)];
	//int cost5 = arrayValues[stop2 + (stop1 * 4)];
	//int cost6 = arrayValues[stop1 + (yNum * 4)];
	//currentCost = cost4 + cost5 + cost6;

	//std::cout << "\nDistance from: " << xNum << " to " << stop2 << " is: " << cost4;
	//std::cout << "\nDistance from: " << stop2 << " to " << stop1 << " is: " << cost5;
	//std::cout << "\nDistance from: " << stop1 << " to " << yNum << " is: " << cost6;





	// Reporting Results

	if (cheapestCost < 999)
		{
			std::cout << "\nThe Cheapest Cost is: " << cheapestCost;
			std::cout << "\nThe Optimal Path is: ";
			
			for (int x = 0; x < 4; x++)
			{
				if (path[x] == 0)
				{
					std::cout << "A ";
				}
				if (path[x] == 1)
				{
					std::cout << "B ";
				}
				if (path[x] == 2)
				{
					std::cout << "C ";
				}
				if (path[x] == 3)
				{
					std::cout << "D ";
				}
			}
		}
	else
		{
			std::cout << "\nThere is no path available.";
		}
}
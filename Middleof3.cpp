// CPP program to find middle of three distinct
// numbers
#include <bits/stdc++.h>
using namespace std;

int middleOfThree(int a, int b, int c)
{
	// Checking for b
	if ((a < b && b < c) || (c < b && b < a))
	return b;

	// Checking for a
	else if ((b < a && a < c) || (c < a && a < b))
	return a;

	else
	return c;
}

// Driver Code
int main()
{
	int a = 20, b = 30, c = 40;
	cout << middleOfThree(a, b, c);
	return 0;
}


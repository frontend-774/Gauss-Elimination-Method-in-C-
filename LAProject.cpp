#include<iostream>		 
#include<iomanip>
#include<math.h>
#include<stdlib.h>

#define  ARRSIZE   10

using namespace std;

int main()
{
	float a[ARRSIZE][ARRSIZE], x[ARRSIZE], ratio;
	int i, j, k, n , count = 0 ;

	cout << setprecision(3) << fixed;

	cout << "Enter number of unknowns: ";
	cin >> n;

	cout << "Enter Coefficients of Augmented Matrix: " << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "\n-------------------------\n";
		for (j = 1; j <= n + 1; j++)
		{
			if (j == 4)
			{
				cout << "Enter 'B_r " << i <<"' Colum : ";
				cin >> a[i][j];
				break;
			}
			cout << "row : "<< i <<"[" << i << "]" << j << "]= ";
			cin >> a[i][j];
		}
		cout << "\n-------------------------\n";
	}

	/* **************Applying Gauss Elimination********************* */

	for (i = 1; i <= n - 1; i++)
	{
		if (a[i][i] == 0.0)
		{
			cout << "Mathematical Error!";
			exit(0);
		}
		for (j = i + 1; j <= n; j++)
		{
			ratio = a[j][i] / a[i][i];

			for (k = 1; k <= n + 1; k++)
			{
				a[j][k] = a[j][k] - ratio * a[i][k];
				if (i == 2)
				{
					if (a[j][k] == 0)
					{
						count++;
					}
				}
				
			}
		
		}
	}

	/* *********** Obtaining Solution by Back Substitution Method  *********** */
	
	x[n] = a[n][n + 1] / a[n][n];

	for (i = n - 1; i >= 1; i--)
	{
		x[i] = a[i][n + 1];
		for (j = i + 1; j <= n; j++)
		{
			x[i] = x[i] - a[i][j] * x[j];
		}
		x[i] = x[i] / a[i][i];
	}

	/* *********** Displaying Solution *********** */
	
	cout << endl << "------------Solution: -----------" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "var_[" << i << "] = " << x[i] << endl;
	}
	if (count == 2 )
	{
		cout << "\nSolution is unique...:\n";
	}
	if (count == 0)
	{
		cout << "\nSolution is Infinity...:\n";
	}
	if (count == 1)
	{
		cout << "\nSolution is No...:\n";
	}

	return(0);
}


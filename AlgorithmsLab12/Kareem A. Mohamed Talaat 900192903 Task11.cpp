#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ** get_optimal_split(int a[], int n)
{
	int** m;
	int** s;
	m = new int* [n];
	s = new int* [n];
	for (int i = 0; i < n; i++)
	{
		m[i] = new int[n];
		s[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				m[i][i] = 0;
			}
			else m[i][j] = -1;
		}
		
	}
	
	int min = 9999999999;
	int tmp;
	int S;
	
	int test = n-1;
	for (int l = 2; l < n; l++)
	{
		for (int i = 1; i < n-l+1; i++)
		{
			int j = i + l- 1;
				if (i < j)
				{
					min = 9999999999999;
					for (int k = i; k < j; k++)
					{
						tmp = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j];
						if (min > tmp)
						{
							min = tmp;
							S = k;
						}
					}
					m[i][j] = min;
					s[i][j] = S;
				}
		}
		test--;
	}
	return s;
}


void print_optimal(int a[], int n)
{
	int** s;
	s = get_optimal_split(a, n);
	vector<string> text;
	for (int i = 0; i < n - 1; i++)
	{
		text.emplace_back("A" + to_string(i + 1));
	}
	
	int* b;
	b = new int[n - 3];
	b[0] = s[1][n - 1];
	for (int i = n - 2; i > 2; i--)
	{
		b[i - 2] = s[1][b[i - 3]];

	}
	
	int temp = 0;
	for (int i = 0; i < n-3; i++)
	{
		text.insert(text.begin() + b[i] + temp, ")");
		if (i!=n-2)
		{
			text.insert(text.begin(), "(");
		}
		temp++;
	}
	for (int i = 0; i < text.size(); i++)
	{
		cout << text[i];
	}
}


int main()
{
	int a[5] = { 5,4,6,2,7 };
	
	int n = 5;
	cout << "Example 1: " << endl;
	print_optimal(a, n);

	cout << "\n________________________________________________" << endl << endl;

	cout << "Example 2: " << endl;
	int b[5] = { 4,4,6,12,7 };
	n = 5;
	print_optimal(b, n);
	cout << endl;
	system("pause");
	return 0;
}
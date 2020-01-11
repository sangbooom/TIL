/******************************
Author : 박상범
Language : C++
Problem : https://www.acmicpc.net/problem/2309
******************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum = 0;
vector<int> v;

void asd() {
	for (int a = 0; a < 9; a++) 
	{
		for (int b = a + 1; b < 9; b++) 
		{
			if (sum - v[a] - v[b] == 100) 
			{
				for (int i = 0; i < 9; i++) 
				{
					if (i != a && i != b) 
					{
						cout << v[i] << "\n";
					}
				}
				return;
			}
		}
	}
}

int main() {

	for (int i = 0; i < 9; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
		sum += n;
	}

	sort(v.begin(), v.end());

	asd();

	return 0;
}

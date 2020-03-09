#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;
int solution(vector<int> d, int budget) {
	int count = 0;
	int sum = 0;
	sort(d.begin(), d.end());
	for (int num : d) {
		sum += num;
		if (sum <= budget)
		{
			count++;
		}
		else {
			break;
		}
	}
	return count;
}

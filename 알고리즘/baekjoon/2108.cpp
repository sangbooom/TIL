#include <bits/stdc++.h>
using namespace std;
int main(){
	int M;
	int sum=0;
	int temp=0;
	int	mode = 0;
	bool isSecond = false;
	cin >> M;
	
	vector<int> n(M);
	vector<int> n2(8001,0);
	
	for(int i=0; i<M; i++){
		cin >> n[i];
		sum += n[i];
		temp = (n[i] <= 0) ? abs(n[i]) : n[i] + 4000;
        n2[temp]++;
	}
	sort(n.begin(), n.end());
	int maxValue2 = *max_element(n2.begin(),n2.end());
	
    for(int i = -4000; i <= 4000; i++){
        temp = i <= 0 ? abs(i) : i+4000;
    }
    
	//1
	cout << round(sum/(double)(M)) << "\n";
	//2
	cout << n[M/2] << "\n";
	//3
	cout << mode << "\n";
	//4
	cout << n[M-1] - n[0] << "\n";
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	int save = 0;
	int seq = 0;
	queue<int> card;
	cin >> N;
	for(int i=0; i<N; i++){
		card.push(i+1);
	}
	while(card.size() != 1){
		if(seq % 2 == 0){
			card.pop();
		} else {
			save = card.front();
			card.pop();
			card.push(save);
		}
		seq++;
	}
	cout << card.front();
	
	return 0;
}

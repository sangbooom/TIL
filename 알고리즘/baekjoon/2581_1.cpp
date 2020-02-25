#include <iostream>
#include <vector>
using namespace std;
int M,N;
int Min;
bool flag;
long long IsPrimeSeive(){
	long long sum = 0;
	vector<bool> primes(N+1);
	
	for(int i=2; i<=N; i++){
		if(primes[i]){
			continue;
		}
		if(i>=M){
			if(!primes[i]){
				sum += i;
				if(!flag){
					Min = i;
					flag = true;
				}
			}
		}
		for(int j=2*i; j<=N; j+=i){
			primes[j] = true;
		}
	}
	return sum;
}

int main(){
	cin >> M >> N;
	if(M<1 || N<1 || M > N){
		return 0;
	}
	
	if(IsPrimeSeive()){
		cout << IsPrimeSeive() << "\n" << Min;
	} else{
		cout << "-1";
	}
	return 0;
}

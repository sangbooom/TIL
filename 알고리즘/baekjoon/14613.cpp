#include <bits/stdc++.h>
using namespace std;

double dp[21][3001];

int main(){
	double W,L,D;

	cin >> W >> L >> D;
	
	dp[0][2000] = 1;
	
	for(int i=1; i<=20; i++){
		for(int j=1000; j<=3000; j++){
			if(dp[i-1][j] == 0) continue;
			
			dp[i][j-50] += dp[i-1][j] * L;
			dp[i][j+50] += dp[i-1][j] * W;
			dp[i][j] += dp[i-1][j] * D;	
		}
	}
	double b,s,g,p,d;
	b=s=g=p=d= 0;
	
	for(int i=1000; i<=3000; i++){
		if (1000 <= i && i <= 1499) b += dp[20][i];
        else if (1500 <= i && i <= 1999) s += dp[20][i];
        else if (2000 <= i && i <= 2499) g += dp[20][i];
        else if (2500 <= i && i <= 2999) p += dp[20][i];
        else d += dp[20][i];
	}
	
    printf("%.8f\n", b);
    printf("%.8f\n", s);
    printf("%.8f\n", g);
    printf("%.8f\n", p);
    printf("%.8f", d);
	
	return 0;
}

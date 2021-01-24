#include <iostream>
using namespace std;
using ll = long long;

ll pow(ll A, ll B, ll C)
{
    if (B == 1){
    	return A % C;
	}
    else
    {
        ll temp = pow(A, B/2, C);
        if (B % 2 == 1)
            return ((temp*temp) % C * A) % C;
        else
            return (temp*temp) % C;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll A, B, C;
    cin >> A >> B >> C;
    cout << pow(A, B, C) << "\n";
	return 0;
}



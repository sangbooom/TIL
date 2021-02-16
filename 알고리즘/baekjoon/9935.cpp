#include <bits/stdc++.h>
using namespace std;

string str, bomb;
vector<char> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> str >> bomb;
    for(int i = 0; i < str.size(); i++){
        s.push_back(str[i]);
        if(s.size() >= bomb.size() && str[i] == bomb[bomb.size()-1]){
            bool boom = true;
            for(int j = 1; j <= bomb.size(); j++){
                if(bomb[bomb.size() - j] != s[s.size() - j]){
                    boom = false;
                }
            }
            if(boom){
                for(int j = 0; j < bomb.size(); j++){
                    s.pop_back();
                }
            }
        }
    }
    if(s.size() == 0){
        cout << "FRULA" << "\n";
        return 0;
    }
    for(int i = 0; i < s.size(); i++){
        cout << s[i];
    }
    cout << "\n";
    return 0;
}

// 시간초과 

//#include <bits/stdc++.h>
//using namespace std;
//string s,bomb,answer;
//int main(){
//    cin >> s >> bomb;
//    int bomb_len = bomb.size();
//	for(int i=0; i<s.size(); i++){
//		if(s[i] == bomb[bomb.size()-1] && i >= bomb_len - 1){
//			int cnt = 1;
//			for(int j=i-1; j>i-bomb_len; j--){
//				if(s[j] == bomb[bomb_len-cnt-1]){
//					++cnt;
//				}
//			}
//			if(cnt == bomb.size()){
//				s.erase(i-bomb_len+1, bomb_len);
//			}
//			i -= bomb_len;
//		}
//	}
//	if(s.size() == 0){
//		cout << "FRULA";
//		return 0;
//	}
//	cout << s;
//	return 0;
//}

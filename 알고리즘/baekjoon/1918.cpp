#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin >> str;
	string result;
	stack<char> s;

	for (int i = 0; i < str.length(); i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z') {
			result += str[i];
		} else {
			switch (str[i]){
				case '(':
					s.push(str[i]);
					break;
				case '*':
				case '/':
					//우선순위 제일 높으므로 같은 기호들 pop
					while (!s.empty() && (s.top() == '*' || s.top() == '/'))
					{
						result += s.top();
						s.pop();
					}
					s.push(str[i]);
					break;
				case '+':
				case '-':
					//우선순위 같거나 높은 기호들 pop
					while (!s.empty() && s.top() != '(')
					{
						result += s.top();
						s.pop();
					}
					s.push(str[i]);
					break;
				case ')':
					//'('가 나올 때까지 다 pop
					while (!s.empty() && s.top() != '(')
					{
						result += s.top();
						s.pop();
					}
					//'(' pop
					s.pop();
					break;
			}
		}
	}
	while (!s.empty())
	{
		result += s.top();
		s.pop();
	}
	cout << result;
	return 0;
}

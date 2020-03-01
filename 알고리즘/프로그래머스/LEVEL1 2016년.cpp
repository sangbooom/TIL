#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    string day[]= {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int today = 0;
    for(int i=0; i<a-1; i++){
        today += month[i];
    }
    answer = day[(b-1 + today) % 7];
    return answer;
}
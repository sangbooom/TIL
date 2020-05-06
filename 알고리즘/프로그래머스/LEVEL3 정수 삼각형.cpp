#include <string>
#include <vector>

using namespace std;
int max(int x, int y){
    return x > y ? x : y;
}
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int v[501][501];
    v[0][0] = triangle[0][0];
    for(int i=1; i<triangle.size(); i++){
        for(int j=0; j<=i; j++){
            if(j==0){
                v[i][j] = v[i-1][j] + triangle[i][j];
            } else if(i==j){
                v[i][j] = v[i-1][j-1] + triangle[i][j];
            } else {
                v[i][j] = max(v[i-1][j-1],v[i-1][j]) + triangle[i][j];
            }
            if(i==triangle.size()-1){
                answer = max(answer, v[i][j]);
            }   
        }
    }
    return answer;
}

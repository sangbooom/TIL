#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0; i<skill_trees.size(); i++){
        vector<int> save(skill.length(),999);
        for(int k=0; k<skill.length(); k++){
            for(int j=0; j<skill_trees[i].length(); j++){
                if(skill[k] == skill_trees[i][j]){
                    save[k] = j;
                }
            }
        }
        int no_skill = 0;
        for(int a=1; a<skill.length(); a++){
            if(save[a-1] > save[a]){
                no_skill++;
                break;
            }
        }
        if(no_skill == 0){
            answer++;
        }
        no_skill = 0;
        save.clear();
    }
    return answer;
}
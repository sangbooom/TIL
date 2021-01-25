#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string answer = "";
    //1
    for(int i=0; i<new_id.size(); i++){
        if(new_id[i] >= 65 && new_id[i] <= 90){
            new_id[i] += 32;
        }
    }
    
    //2
    for(int i=0; i<new_id.size(); i++){
        if((new_id[i] >= 0 && new_id[i] <= 44) || new_id[i] == 47 || (new_id[i] >= 58 && new_id[i] <= 94)
           || new_id[i] == 96 || new_id[i] >= 123){
            new_id.erase(i,1);
            i--;
        } 
    }
    
    //3
    for(int i=0; i<new_id.size(); i++){
        if(new_id[i] == 46){
            for(int j=i+1; j<new_id.size(); j++){
                if(new_id[j] == 46){
                    new_id.erase(j,1);
                    j--;
                } else {
                    break;
                }
            }
        }
    }
    
    //4
    if(new_id[0] == 46 ){
       new_id.erase(0,1);
    }
    if(new_id[new_id.size()-1] == 46){
       new_id.erase(new_id.size()-1,1);
    }
   
    
    //5
    if(new_id == ""){
        new_id = "a";
    }
    
    //6
    if(new_id.size() >= 16){
        for(int i=15; i<new_id.size(); i++){
            new_id.erase(i,1);
            i--;
        }
        if(new_id[new_id.size()-1] == 46){
            new_id.erase(new_id.size()-1,1);
        }
    }
    
    //7
    if(new_id.size() <= 2){
        while(new_id.size() != 3){
            new_id += new_id[new_id.size()-1];
        }
    }
    
    answer = new_id;
    
    return answer;
}

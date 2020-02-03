#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'collision' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY speed
 *  2. INTEGER pos
 */

int collision(vector<int> speed, int pos) {
    int count =0;

    for(int i=0; i<=pos-1; i++){
        if(speed[pos] < speed[i]){
            count++;
        }    
    }
    for(int i=pos+1; i<speed.size(); i++){
        if(speed[pos] > speed[i]){
            count++;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string speed_count_temp;
    getline(cin, speed_count_temp);

    int speed_count = stoi(ltrim(rtrim(speed_count_temp)));

    vector<int> speed(speed_count);

    for (int i = 0; i < speed_count; i++) {
        string speed_item_temp;
        getline(cin, speed_item_temp);

        int speed_item = stoi(ltrim(rtrim(speed_item_temp)));

        speed[i] = speed_item;
    }

    string pos_temp;
    getline(cin, pos_temp);

    int pos = stoi(ltrim(rtrim(pos_temp)));

    int result = collision(speed, pos);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

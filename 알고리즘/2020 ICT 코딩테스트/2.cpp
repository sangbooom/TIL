#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'maxDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY nums as parameter.
 */

int maxDifference(vector<int> nums) {
    
    int start = 0;
    int end = nums.size()-1;
    vector<int> sum;

    while(1){
        if(end == 0){
            break;
        }
        else if(nums[end] < nums[end-1]){
            end--;
            if(end == 0){
                return -1;
            }
        }
        else if(nums[end] >= nums[end-1]){
            while(end!=start){
                if((nums[end] - nums[start]) > 0){
                    sum.push_back(nums[end]-nums[start]);
                    start++;
                }else{
                    start++;
                }
            }
            end--;
            start =0;
            if(end == 0){
                break;
            }     
        }
    }
    int end2 = sum.size()-1;
    if(end2 <= 0){
        return -1;
    }
    
    sort(sum.begin(),sum.end());
    int result = sum[end2];

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nums_count_temp;
    getline(cin, nums_count_temp);

    int nums_count = stoi(ltrim(rtrim(nums_count_temp)));

    vector<int> nums(nums_count);

    for (int i = 0; i < nums_count; i++) {
        string nums_item_temp;
        getline(cin, nums_item_temp);

        int nums_item = stoi(ltrim(rtrim(nums_item_temp)));

        nums[i] = nums_item;
    }

    int result = maxDifference(nums);

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

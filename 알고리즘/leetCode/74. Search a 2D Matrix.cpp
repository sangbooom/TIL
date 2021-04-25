class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size()-1;
        int m = matrix[0].size()-1;
        while(n > 0 && matrix[n-1][m] >= target) n--;
        while(m > 0 && matrix[n][m-1] >= target) m--;
        if(matrix[n][m] == target){
            return true;
        } else {
            return false;
        }
    }
};

//처음 js풀이
// var searchMatrix = function(matrix, target) {
//     for(let i=0; i<matrix.length; i++){
//         for(let j=0; j<matrix[0].length; j++){
//             if(matrix[i][j] === target){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

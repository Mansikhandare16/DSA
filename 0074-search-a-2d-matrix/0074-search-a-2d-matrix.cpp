class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int low=0;
        int high=n*m-1; //last vaale element ke liye

        while(low<=high){
            int guess=low+(high-low)/2;
            int row= guess/m; //konse row mein hai guess
            int col=guess%m; //konse col mein hai (current row mein kitni position aage hain eg 7=3*2+1) thats why remainder

            if(matrix[row][col]==target){
                return true;
            }
            if(matrix[row][col]>target){
                high=guess-1;
            }
            else{
                low=guess+1;
            }
        }
        return false;
    }
};
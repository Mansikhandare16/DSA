class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int n=matrix.size();

        for(int i=0;i<n;i++){
            pq.push({matrix[i][0],i,0});
        }
        while(!pq.empty()){
            vector<int> top =pq.top();
            pq.pop();
            
            int value=top[0];
            int row=top[1];
            int col=top[2];

            k--;
            if(k==0){
                return value;
            }
            
            if(col+1<n){
                pq.push({matrix[row][col+1],row,col+1});
            }
        }
        return -1;
    }
};
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxend=0; 
        int minend=0;
        int minsum=INT_MAX;
        int maxsum=INT_MIN;

        for(int x:nums){
            maxend=max(x,x+maxend);
            maxsum=max(maxsum,maxend);

            minend=min(x,x+minend);
            minsum=min(minsum,minend);
        }
        return max(abs(maxsum),abs(minsum));
    }
};
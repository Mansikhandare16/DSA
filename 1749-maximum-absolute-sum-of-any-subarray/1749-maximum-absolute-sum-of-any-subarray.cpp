class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxend=0; 
        int minend=0;
        int minsum=INT_MAX;
        int maxsum=INT_MIN;

        for(int i=0;i<nums.size();i++){
            maxend=max(nums[i],nums[i]+maxend);
            maxsum=max(maxsum,maxend);

            minend=min(nums[i],nums[i]+minend);
            minsum=min(minsum,minend);
        }
        return max(abs(maxsum),abs(minsum));
    }
};
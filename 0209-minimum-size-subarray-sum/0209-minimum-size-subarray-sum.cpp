class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0;
        int high=0;
        int res=INT_MAX;
        int sum=0;

        while(high<nums.size()){
            sum+=nums[high];

            while(sum>=target){
                int len=high-low+1;
                res=min(len,res);
                sum-=nums[low];
                low++;
            }
            high++;
        }

        return res==INT_MAX? 0:res;
    }
};
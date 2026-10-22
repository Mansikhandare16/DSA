class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int guess=low+(high-low)/2;
            if(nums[guess]<target){
                low=guess+1;
            }
            else if(nums[guess]>target){
                high=guess-1;
            }
            else{
                ans[0]=guess;
                high=guess-1;
            }
        }
        low=0;
        high=nums.size()-1;

        while(low<=high){
            int guess=low+(high-low)/2;
            if(nums[guess]<target){
                low=guess+1;
            }
            else if(nums[guess]>target){
                high=guess-1;
            }
            else{
                ans[1]=guess;
                low=guess+1;
            }
        }
        return ans;
    }
};
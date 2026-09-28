class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start=0;
        int res=1;
        int j=1;
        while(j<nums.size()){
            if(nums[start]==nums[j]){
                j++;
                continue;
            }
            nums[start+1]=nums[j++];
            start++;
            res++;
        }
        return res;
    }
};
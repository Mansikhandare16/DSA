class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zeroes=0;
        int ones=0;
        unordered_map<int,int> mp;
        int res=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeroes++;
            }
            else{
                ones++;
            }
            int diff=zeroes-ones;

            if(diff==0){
                res=max(res,i+1);
                continue;
            }

            if(mp.find(diff)==mp.end()){
                mp[diff]=i;
            }
            else{
                int idx=mp[diff];
                int len=i-idx;
                res=max(res,len);
            }
        }
        return res;
    }
};
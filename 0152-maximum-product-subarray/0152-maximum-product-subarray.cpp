class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxend=nums[0];
        int minend=nums[0];
        int maxprod=nums[0];

        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=nums[i]*maxend;
            int v3=nums[i]*minend;

            maxend=max(v1,max(v2,v3));
            minend=min(v1,min(v2,v3));
            maxprod=max(maxprod, max(maxend,minend));
        }
        return maxprod;
    }
};
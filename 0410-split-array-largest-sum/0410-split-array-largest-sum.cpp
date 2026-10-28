class Solution {
public:
    bool fun(vector<int> &nums,int n,int k,int limits){
        int parts=1;
        long long sum=0;

        for(int i=0;i<n;i++){
            if(nums[i]+sum <=limits){
                sum+=nums[i];
            }
            else{
                parts++;
                sum=nums[i];
                if(parts>k){
                    return false;
                }
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        long long low=0,high=0;

        for(int i=0;i<n;i++){
            low=max((long long)nums[i],low);
            high+=nums[i];
        }

        long long ans=-1;

        while(low<=high){
            long long guess=low+(high-low)/2;

            if(fun(nums,n,k,guess)){
                ans=guess;
                high=guess-1;
            }
            else{
                low=guess+1;
            }
        }
        return ans;
    }
};
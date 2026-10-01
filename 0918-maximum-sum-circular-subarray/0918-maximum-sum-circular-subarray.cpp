class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0;
        int maxend=0;
        int maxsum=INT_MIN;
        int minend=0;
        int minsum=INT_MAX;

        for(int x:nums){ //normal kadane ke tarike se pehle max aur min sum nikaalo
            maxend=max(x,x+maxend);
            maxsum=max(maxsum,maxend);

            minend=min(x,x+minend);
            minsum=min(minsum,minend);

            total+=x;
        }

        if(maxsum<0){ // agar saare element in array -ve hai toh
            return maxsum;
        }

        return max(maxsum,total-minsum); //for circular sum
    }
};
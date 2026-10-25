class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int day){
        int flowers=0;
        int bouquets=0;
        
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                flowers++;
                if(flowers==k){ //har ek bouquet  mein mein k flowers chahiye
                    bouquets++;
                    flowers=0;
                }
            }
            else{
                flowers=0;
            }
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n) return -1;

        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int res=-1;

        while(low<=high){
            int guess=low+(high-low)/2;
            if(possible(bloomDay,m,k,guess)){
                res=guess;
                high=guess-1;
            }
            else{
                low=guess+1;
            }
        }  
        return res; 
    }
};
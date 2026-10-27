class Solution {
public:
    bool fun(vector<int> & candies, long long k,int guess){
        long long children=0;
        for(int i=0;i<candies.size();i++){
            children+=candies[i]/guess;
        }
        return children>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1;
        int high=*max_element(candies.begin(),candies.end());
        int res=0;

        while(low<=high){
            int guess=low+(high-low)/2;

            if(fun(candies,k,guess)){
                res=guess;
                low=guess+1; //possible hai toh aur bada maximum try karo
            }
            else{
                high=guess-1;
            }
        }
        return res;
    }
};
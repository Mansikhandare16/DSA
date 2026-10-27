class Solution {
public:
    bool fun(vector<int> &weights,int days, int capacity){
        int daysNeeded=1;
        int currentload=0;

        for(int i=0;i<weights.size();i++){
            if(currentload+weights[i]>capacity){
                daysNeeded++;
                currentload=weights[i]; //new day mein new currentload aayega matlab jo curr element hai
            }
            else{
                currentload+=weights[i];
            }
        }
        return daysNeeded <=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end()); //because max element ka weight nahi jhel paaya then packages wont load
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=high;

        while(low<=high){
            int guess=low+(high-low)/2;

            if(fun(weights,days,guess)){
                ans=guess;
                high=guess-1; //aur chhota dekho
            }
            else{
                low=guess+1;
            }
        }
        return ans;
    }
};
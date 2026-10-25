class Solution {
public:
    long long fun(vector<int>& piles, int n,int speed){
        long long h=0;
        for(int i=0;i<piles.size();i++){
            h=h+piles[i]/speed; //kitna hours lagenge basis on speed
            if(piles[i]%speed != 0){ //agar remainder reh jaata hai then
                h++;
            }
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int res=-1;

        while(low<=high){
            int guess=low+(high-low)/2;//speed
            long long hour=fun(piles,n,guess); 
            if(hour>h){
                low=guess+1; //speed inc
            }
            else{
                res=guess;
                high=guess-1;
            }
        }
        return res;
    }
};
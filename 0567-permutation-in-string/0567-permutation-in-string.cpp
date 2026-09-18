class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        
        
        if(n>m) return false;

        vector<int> need(26,0);
        vector<int> have(26,0);
        
        for(char ch:s1){
            need[ch-'a']++;
        }

        int l=0;
        for(int r=0;r<m;r++){
            have[s2[r]-'a']++;

            if(r-l+1 > n){
                have[s2[l]-'a']--;
                l++;
            }
            if(have==need){
                return true;
            }
        }
        return false;
    }
};
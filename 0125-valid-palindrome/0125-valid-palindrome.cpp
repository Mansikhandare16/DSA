class Solution {
public:
    bool fun(string &s, int low,int high){
        while(low<high && !isalnum(s[low])){
            low++;
        }
        while(low<high && !isalnum(s[high])){
            high--;
        }
        if(low>=high){
            //pura ya toh bich mein aagye yaa phir crossed
            return true;
        }
        if(tolower(s[low])!=tolower(s[high])){
            return false;
        }
        return fun(s,low+1,high-1);
    }
    bool isPalindrome(string s) {
        return fun(s,0,s.size()-1);
    }
};
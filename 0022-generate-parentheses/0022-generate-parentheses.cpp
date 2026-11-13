class Solution {
public:
   void fun(int n,int open,int close,string &tmp, vector<string>&res) {
        if(open==n && close==n){
            res.push_back(tmp);
            return;
        }

        //opening
        if(open<n){
            tmp.push_back('(');
            fun(n,open+1,close,tmp,res);
            tmp.pop_back();
        }
        //clsoing
        if(close<open){
            tmp.push_back(')');
            fun(n,open,close+1,tmp,res);
            tmp.pop_back();
        }
        return;
   }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp="";
        fun(n,0,0,tmp,res);
        return res;
    }
};
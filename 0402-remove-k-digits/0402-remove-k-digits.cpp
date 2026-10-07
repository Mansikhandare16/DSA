class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char ch:num){
            while(!st.empty() && k>0 && st.top()>ch){
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while(k>0 && !st.empty()){   //agar left mein koi bada hai hi nahi then remove from last
            st.pop();
            k--;
        }
        
        string ans="";

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size() && ans[i]=='0'){  //leading zeroes ke liye
            i++;
        }
        ans=ans.substr(i);
        if(ans==""){
            return "0";
        }
        return ans;
    }
};
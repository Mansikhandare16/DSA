class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp="";

        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                if(temp=="" || temp=="."){
                    temp="";
                    continue;
                }
                else if(temp==".."){
                    if(!st.empty()){
                        st.pop();
                    }
                }
                else{
                    st.push(temp);
                }

                temp="";
            }
            else{
                temp+=path[i];
            }

        }
        if(temp==".."){
            if(!st.empty()){
                st.pop();
            }
        }
        else if(temp!="" && temp!="."){
            st.push(temp);
        }

        vector<string> arr;
        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }

        reverse(arr.begin(),arr.end());

        string ans="";
        for(string s:arr){
            ans+="/"+s;
        }
        if(ans==""){
            ans+="/";
        }
        return ans;
    }
};
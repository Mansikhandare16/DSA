class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int power=0; //delete ho gaya hai
        int nopower=arr[0]; //delete nahi hua hai
        int res=arr[0];

        for(int i=1;i<arr.size();i++){
            int v1=arr[i];
            int v2=nopower+arr[i];
            int v3=power+arr[i]; //pehele hi delete hogaya
            int v4=nopower; //curr ko delete kara;

            res=max(res, max(max(v1,v2),max(v3,v4)));
            
            power=max(v3,v4);
            nopower=max(v1,v2);
        }
        return res;
    }
};
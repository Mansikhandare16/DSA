class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> prof;

        for(int i=0;i<n;i++){
            prof.push_back({capital[i],profits[i]});
        }
        sort(prof.begin(),prof.end());
        priority_queue<int> pq;
        int idx=0;

        while(k--){
            while(idx<n){
                if(prof[idx].first>w){
                    break;
                }
                pq.push(prof[idx].second);
                idx++;
            }
            if(pq.empty()){
                return w;
            }
            w=w+pq.top();
            pq.pop();
        }
        return w;
    }
};
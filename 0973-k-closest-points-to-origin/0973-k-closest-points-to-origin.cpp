class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq ;//first dist, second mein x and y
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];

            int dist=x*x+y*y;

            pq.push({dist,{x,y}});

            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            auto p=pq.top().second;
            ans.push_back({p.first,p.second});
            pq.pop();
        }
        return ans;
    }
};
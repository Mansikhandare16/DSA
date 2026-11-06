class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }

        priority_queue<int> pq;

        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }

        queue<pair<int,int>> q; //{remaining freq,available time}
        int time=0;

        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int remaining=pq.top()-1;
                pq.pop();
                
                if(remaining>0){
                    q.push({remaining,time+n});
                }
            }
            if(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //create an adjacecy list
       vector<pair<int,int>> v[n+1];
        for(auto i:times){
            v[i[0]].push_back({i[1],i[2]});
        }
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k]=0;
        dist[0]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int next=pq.top().second;
            pq.pop();
            for(auto i:v[next]){
                if(dist[i.first]>d+i.second){
                    dist[i.first]=d+i.second;
                    pq.push({dist[i.first],i.first});
                }
            }
        }
        int mn=0;
        for(auto i:dist){
            if(i==1e9)return -1;
            mn=max(mn,i);
        }
        return mn;
    }
};

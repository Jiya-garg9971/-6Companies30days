
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=(int)(1e9+7);
        vector<long long int> dist(n+1,1e18);
        vector<long long int> ways(n+1,0);
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>> ,greater<pair<long long int,int>>> pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        vector<pair<int,long long int>>adj[n+1];
        for(auto i:roads){
            adj[i[0]].push_back({i[1],(long long )i[2]});
            adj[i[1]].push_back({i[0],(long long)i[2]});            
        }
        while(!pq.empty()){
            
            long long int cost=pq.top().first;
            int next=pq.top().second;
            pq.pop();
            if(cost>dist[next]){continue;}
            for(auto i:adj[next]){
                int node=i.first;
                if( cost+(long long)i.second < dist[node]){
                    dist[node]=cost+(long long)i.second;
                    ways[node]=ways[next];
                    if(node!=n-1) pq.push({cost+(long long)i.second,node});;
                }
                else if(cost+(long long)i.second==dist[node]){
                    ways[node]=(ways[node]+ways[next])%mod;
                }                
            }
        }
        cout<< (1e9+7>940420443)<<endl;
        return ways[n-1]%mod;
    }
};

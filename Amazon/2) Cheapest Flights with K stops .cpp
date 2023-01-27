class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n+1,1e9);
      queue<pair<int,pair<int,int>>> q;
        vector<pair<int,int>> adj[n+1];
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        int ans=INT_MAX;
        q.push({0,{src,k+1}});
        dist[src]=0;
        while(!q.empty()){
            int charge=q.front().first;
            int step=q.front().second.second;
            int from=q.front().second.first;
            q.pop();
            if(step>0){
                for(auto i:adj[from]){
                    int to=i.first;
                    int c=i.second;  
                    if(charge+c<dist[to]){
                        q.push({charge+c,{to,step-1}});    
                        dist[to]=charge+c;
                    }                    
                }
            }
            
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};

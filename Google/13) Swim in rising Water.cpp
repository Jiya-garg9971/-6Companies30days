class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
       int n=grid.size();
        vector<vector<int>> seen(n+1,vector<int> (n+1,0));
        seen[0][0]=1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            int prev=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            if(i==n-1 and j==n-1)return prev;
            pq.pop();
            int dx[]={-1,+1,0,0};
            int dy[]={0,0,-1,1};
            for(int k=0;k<4;k++){
                if(i+dx[k]>=0 and i+dx[k]<n and j+dy[k]>=0 and j+dy[k]<n and !seen[i+dx[k]][j+dy[k]]){
                    seen[i+dx[k]][j+dy[k]]=1;
                    pq.push({max(prev,grid[i+dx[k]][j+dy[k]]),{i+dx[k],j+dy[k]}});
                }
            }
        }          
       return 0;
    }
};

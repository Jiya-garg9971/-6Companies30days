class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n+1,vector<int>(n+1,1e9));
        for(auto i:edges){
            dist[i[0]][i[1]]=i[2];
            dist[i[1]][i[0]]=i[2];
        }
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==1e9 || dist[k][j]==1e9 ){
                        continue;
                    }
                    if(dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        int mx=n,city=0;
        for(int i=0;i<n;i++){
            int cnt=-1;
             for(int j=0;j<n;j++){
                 cout<<dist[i][j]<<" ";
                 if(dist[i][j]<=distanceThreshold){
                     cnt++;
                 }
             }
             
             if(cnt<=mx){
                 mx=cnt;
                 city=i;
             }
             cout<<" -> "<<cnt<<" ";
             cout<<endl;
        }
        return city;
    }
};

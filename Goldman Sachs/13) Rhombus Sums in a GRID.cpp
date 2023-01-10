

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int> pq;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            pq.push(grid[i][j]);                       
        }
        for(int l=1;l<=50;l++){
            for(int i=0;i<n-1;i++){
                for(int j=1;j<m-1;j++){
                    int xt=i-l;int yl=j-l;
                    int xd=i+l;int yr=j+l;
                    if(xt<0 || xd>=n || yl<0 || yr>=m)continue;
                    int sum=grid[xt][j]+grid[xd][j]+grid[i][yl]+grid[i][yr];
                    for(int k=1;k<l;k++){
                        sum+=grid[xt+k][j-k];
                    }
                    for(int k=1;k<l;k++){
                        sum+=grid[xt+k][j+k];
                    }
                    for(int k=1;k<l;k++){
                        sum+=grid[xd-k][j-k];
                    }
                    for(int k=1;k<l;k++){
                        sum+=grid[xd-k][j+k];
                    }
                    cout<<sum<<" ";
                    pq.push(sum);
                }                
            } 
        }
        vector<int> ans;
        int a=-1;
        int cnt=0;
        while(cnt<3 and !pq.empty()){
            int b=pq.top();pq.pop();
            if(b!=a){
                ans.push_back(b);
                cnt++;
            }
            a=b;
            
        }
        
        return ans;
    }
};

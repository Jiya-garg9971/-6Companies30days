class Solution {
public:
bool dfs(vector<vector<int>>& grid,int i,int j){
    if(i<0 || i>=grid.size() || j<0 ||j>=grid[0].size() ){
        return false;
    }
    if(grid[i][j]==1){
        return true;
    }
    grid[i][j]=1; //so that wo wapis peeche na aaye.
    bool down= dfs(grid,i+1,j);
    bool up= dfs(grid,i-1,j);
    bool left= dfs(grid,i,j-1);
    bool right= dfs(grid,i,j+1);
    return down && left && up && right;
}
    int closedIsland(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0){
                   cnt+=dfs(grid,i,j)?1:0;
                   
                }
                
            }
        }
        return cnt;
    }
};

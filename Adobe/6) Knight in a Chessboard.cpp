class Solution {
public:

double dfs(int n, int k, int row, int col,vector<vector<vector<double>>> &dp){
    if(row<0 ||row>=n || col<0 || col>=n)return 0;
    if(k==0)return 1;
    if(dp[row][col][k]!=0)return dp[row][col][k];
    int dx[]={-2,2,-2,2,1,-1,1,-1};
    int dy[]={1,1,-1,-1,2,2,-2,-2};
    double rate=0;
    for(int i=0;i<8;i++)
       rate+=0.125*dfs(n,k-1,row+dx[i],col+dy[i],dp);   
    return dp[row][col][k]=rate;
}
    double knightProbability(int n, int k, int row, int column) {
        double ans=0;
        if(k==0)return 1;
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,0)));
       
        return dfs(n,k,row,column,dp);;

    }
};

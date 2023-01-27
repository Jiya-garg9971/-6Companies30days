#define ll long long
class Solution {
public:
int mod=1e9+7;
int helper(int start,int &end,int k, vector<vector<int>> &dp){
    if(k==0 and start==end)return 1;
    if(k==0)return 0;
   // if(abs(end-start)>k)return 0;
    if(dp[start+1000][k]!=-1)return dp[start+1000][k];
    return dp[start+1000][k]=(helper(start+1,end,k-1,dp)+helper(start-1,end,k-1,dp))%mod;   

}
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3000,vector<int>(k+1,-1));
        return helper(startPos,endPos,k,dp);
    }

};

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int rs=max(0,i-k),re=min(n-1,i+k);
                int cs=max(-1,j-k-1),ce=min(m-1,j+k);
                for(int k=rs;k<=re;k++){
                    if(cs<0)
                     ans[i][j]+=mat[k][ce];
                    else
                    ans[i][j]+=(mat[k][ce]-mat[k][cs]);
                }
            }
        }
        return ans;
    }
};

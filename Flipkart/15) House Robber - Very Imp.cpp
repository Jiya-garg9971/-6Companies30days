
class Solution {
public:
int helper(TreeNode* root, bool take,  map<pair<TreeNode*,bool>,int> &dp){
    if(root==NULL){
        return 0;
    }
    if(dp.find({root,take})!=dp.end()){
        return dp[{root,take}];
    }
    int pick=0;
    if(take){
        pick=root->val+helper(root->left,false,dp)+helper(root->right,false,dp);
    }
    int npick=helper(root->left,true,dp)+helper(root->right,true,dp);
    return dp[{root,take}]=max(pick,npick);
}
    int rob(TreeNode* root) {
       map<pair<TreeNode*,bool>,int> dp;
        return helper(root,1,dp);
    }
};

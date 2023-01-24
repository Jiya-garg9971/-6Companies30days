/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt=0;
    vector<int> helper(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        vector<int> lh=helper(root->left);
        vector<int> rh=helper(root->right);
        int sum=root->val+lh[0]+rh[0];
       int totalnodes=lh[1]+rh[1]+1;
        if(sum/totalnodes==root->val){
            cnt++;
        }
        return {sum,totalnodes};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return cnt;
    }
};

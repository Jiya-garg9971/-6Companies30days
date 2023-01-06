/* Q) Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

*/

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
    void inorder(TreeNode* root,vector<int>&a){
        if(root==NULL)return ;
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        inorder(root1,a);
        inorder(root2,a);
        sort(a.begin(),a.end());
        return a;
    }
};

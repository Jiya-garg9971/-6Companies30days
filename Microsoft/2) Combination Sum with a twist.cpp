// Q2) Combination Sum III
class Solution {
public:
void helper(vector<vector<int>>&ans,int target,int k,int i,vector<int>&temp){
    
    if(target==0){
        if(k==temp.size()){
            ans.push_back(temp);
        }
        return ;
    }
    if(i>9){
        return ;
    }
    if(i<=target){
    temp.push_back(i);
    helper(ans,target-i,k,i+1,temp);
    temp.pop_back();}
    helper(ans,target,k,i+1,temp);
    
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans,n,k,1,temp);
        return ans;
    }
};

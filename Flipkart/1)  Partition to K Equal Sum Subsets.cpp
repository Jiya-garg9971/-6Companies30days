class Solution {
public:
    bool helper(int idx,vector<int> &nums,int k,int sum,int req,vector<int>&vis){
        if(k==1)return true;
        if(idx==nums.size())return false;
        if(req==sum)
            return helper(0,nums,k-1,0,req,vis);
        if(!vis[idx] and req>=sum+nums[idx]){
            vis[idx]=1;
           if(helper(idx+1,nums,k,sum+nums[idx],req,vis))return true;
            vis[idx]=0;
        }
       return helper(idx+1,nums,k,sum,req,vis);

    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalsum=0;
        for(auto i:nums)totalsum+=i;
        if(totalsum%k)return false;
        int n=nums.size();
        vector<int> visited(n+1,0);
        //sort(nums.begin(),nums.end());
        return helper(0,nums,k,0,totalsum/k,visited);
    }
};

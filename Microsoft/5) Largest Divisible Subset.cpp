/*Q5) Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        vector<int> hash(n+1,0);
        sort(nums.begin(),nums.end());
        int maxi=0,size=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 and 1+dp[j]>dp[i]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>=size){
                cout<<i<<" ";
                 maxi=i;
                 size=dp[i];
            }
        }
        vector<int> ans(size+1,0);
        while(size>=0){
            ans[size--]=nums[maxi];
            maxi=hash[maxi];
        }
        return ans;
    }
};

class Solution {
public:
long long int mod=1e9+7;
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();

        //FIND THE PREFIX SUM FOR FINDING THE SUM OF EACH SUBARRAY
        vector<long long int> prefixsum(n+1,0);
        for(int i=1;i<=n;i++){
            prefixsum[i]=(prefixsum[i-1]+nums[i-1]);
        }

        //FIND THE MIN VALUE INDEX FROM LEFT
        vector<int> mnleft(n+1,-1);
        stack<int> left;
        for(int i=0;i<n;i++){
            while(!left.empty() and nums[left.top()]>=nums[i])
                left.pop();
            if(!left.empty())
                mnleft[i]=left.top();
            left.push(i);
        }

         //FIND THE MIN VALUE INDEX FROM right
        vector<int> mnright(n+1,n);
        stack<int> right;
        for(int i=n-1;i>=0;i--){
            while(!right.empty() and nums[right.top()]>=nums[i])
                right.pop();
            if(!right.empty())
                mnright[i]=right.top();
            right.push(i);
        }
        //USE THE FORMULA DERIVED
        long long int ans=0;
        for(int i=0;i<n;i++){
            int prev=mnleft[i];
            int next=mnright[i];
            long long a=(prefixsum[next]-prefixsum[prev+1])*nums[i];
            ans=max(ans,a);
        }
         return ans%mod;
    }
};

//Q4) You are given an integer array nums of length n. Return maximum length of Rotation Function.

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0,n=nums.size()-1;
        for(auto i:nums){
            sum+=i;
        }
        int cs=0;
        for(int i=0;i<=n;i++)
            cs+=(i*nums[i]);
        int mx=cs;int i=n;
        int prev=cs;
        while(i>0){
            int cur=prev+sum-((n+1)*nums[i]);
            i--;
            cout<<cur<<" ";
            mx=max(mx,cur);
            prev=cur;
        }
        return mx;
    }
};

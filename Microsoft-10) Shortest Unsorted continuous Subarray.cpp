/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, 
then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftmax(n+1,0);
        vector<int> rightmin(n+1,0);
        int maxl=INT_MIN;
        int minr=INT_MAX;
        for(int i=0;i<n;i++){
            maxl=max(maxl,nums[i]);
            minr=min(minr,nums[n-i-1]);
            leftmax[i]=maxl;
            rightmin[n-i-1]=minr;
        }
        int lo=0;int hi=n-1;
        while(lo<n and nums[lo]<=rightmin[lo])lo++;
        while(lo<hi and nums[hi]>=leftmax[hi])hi--;
        
        return hi-lo+1;
    }
};

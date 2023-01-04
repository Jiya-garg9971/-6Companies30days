/*  Number of Pairs Satisfying Inequality
Q) You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:

0 <= i < j <= n - 1 and
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
Return the number of pairs that satisfy the conditions.

*/
class Solution {
public:
long long int mergesort(vector<int> &a,int l,int h,int diff){
   
    int mid=(l+h)/2;
    int i=l;int j=mid+1;
    vector<int> res;
    long long int cnt=0;
    while(i<=mid && j<=h){
        if(a[i]<=diff+a[j]){
            cnt+=h-j+1;i++;
        }
        else{
            j++;
        }
    }
   //comparison based sorting will not help as we are including that 'diff' in the a. 
    sort(a.begin()+l,a.begin()+h+1);
    return cnt;
}
long long int merge(vector<int> &a,int lo,int hi,int diff){
    if(lo>=hi){
        return 0;
    }
    int mid=(lo+hi)/2;
    long long int rev=merge(a,lo,mid,diff);
    rev+=merge(a,mid+1,hi,diff);
    rev+=mergesort(a,lo,hi,diff);
    return rev;
}
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        for(int i=0;i<nums1.size();i++){
            nums1[i]=nums1[i]-nums2[i];
        }
        
        //then we have to use merge sort
        long long ans=merge(nums1,0,nums1.size()-1,diff);
        return ans;
    }
};

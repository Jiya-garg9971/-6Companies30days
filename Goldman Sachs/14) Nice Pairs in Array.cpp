/*Q) You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. 
For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.
*/
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        map<int,int> mp;
        int mod=1e9+7;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            int rev=0;
            while(n>0){
                int digit=n%10;
                rev=rev*10+digit;
                n/=10;
            }
            mp[i]=rev;
        }
        long long int cnt=0; 
        map<int,long long int> freq;
        for(int i=0;i<nums.size();i++){
            if(freq.find(nums[i]-mp[i])!=freq.end()){
                cnt+=freq[nums[i]-mp[i]]%mod;
            }
           freq[nums[i]-mp[i]]++;
        }
        return cnt%mod;
    }

};

/*
You are given two positive integer arrays nums and numsDivide. You can delete any number of elements from nums.

Return the minimum number of deletions such that the smallest element in nums divides all the elements of numsDivide. If this is not possible, return -1.

Note that an integer x divides y if y % x == 0.

*/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int d=numsDivide[0];
        for(auto i:numsDivide){
            d=gcd(d,i);
            cout<<d<<" ";
        }
      //Finding gcd bcz it is a number which divides all the element of numsDivide array.
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(d%nums[i]==0){
                return i;
            }
        }
        return -1;

    }
};

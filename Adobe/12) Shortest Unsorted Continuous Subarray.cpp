class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> a(nums.begin(),nums.end());
        int n=nums.size();
        int st=0,end=n-1;
        sort(a.begin(),a.end());
       while(st<=end){
           if(nums[st]==a[st])st++;
           else if(nums[end]==a[end])end--;
            else{break;}
       }
        return end-st+1;
    }
};

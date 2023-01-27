class Solution {
public:
vector<int> v;
vector<int> ans;
int n=0;
    Solution(vector<int>& nums) {
        v=nums;
        n=nums.size();
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
         ans=v;
         for(int i=0;i<n;i++){
             int idx=rand()%(n-i);
            swap(ans[idx+i],ans[i]);
         }        
        return ans;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

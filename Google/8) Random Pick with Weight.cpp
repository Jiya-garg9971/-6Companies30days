class Solution {
public:
vector<int> a;
    Solution(vector<int>& w) {
       for(auto i:w){
           if(a.empty())
           a.push_back(i);
           else
           a.push_back(i+a.back());
       }
    }
    
    int pickIndex() {
        int n=rand()%a.back();
        int idx=upper_bound(a.begin(),a.end(),n)-a.begin();
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

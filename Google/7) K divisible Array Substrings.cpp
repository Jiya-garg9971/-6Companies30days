class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {       
        set<vector<int>> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int cnt=0;
           vector<int> v;
            for(int j=i;j<n;j++){
                if(nums[j]%p==0)cnt++;
                if(cnt>k)break;
                v.push_back(nums[j]);
                st.insert(v);
            }
        }
        return st.size();
    }
};

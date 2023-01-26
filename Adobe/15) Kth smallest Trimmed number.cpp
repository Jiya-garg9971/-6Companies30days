class Solution {
public:
   
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> ans;
        for(auto j:queries){
            priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>> pq;
            int trim=j[1];
            for(int i=0;i<n;i++){
                int a=nums[i].length();
                //cout<<nums[i].substr(a-trim,trim)<<" ";
                pq.push({nums[i].substr(a-trim,trim),i});
            }
            int cnt=0;
            while(cnt<j[0]-1){
                pq.pop();cnt++;
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};

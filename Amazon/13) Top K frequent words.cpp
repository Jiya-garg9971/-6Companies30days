class Solution {
public:
     static bool cmp(pair<string,int> a,pair<string,int> b){
         if(a.second== b.second)
             return a.first<b.first;
        return a.second> b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        vector<string> ans;
        vector<pair<string,int>> st(mp.begin(),mp.end());
        
        sort(st.begin(),st.end(),cmp);
        int c=0;
        for(auto i: st){
            ans.push_back(i.first);
            c++;
            if(c==k){
                break;
            }
        }
        return ans;
    }
};

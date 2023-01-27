class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,pair<string,long long>> freq;
        map<string,long long> id;
        long long n=creators.size();
        for(long long i=0;i<n;i++){
            if(freq.count(creators[i])){
                if(views[i]>id[creators[i]] || ( views[i]==id[creators[i]]  and ids[i]<freq[creators[i]].first)){
                    freq[creators[i]]={ids[i],freq[creators[i]].second+views[i]};
                    
                }
                else{
                    freq[creators[i]].second+=views[i];
                }
                id[creators[i]]=max(id[creators[i]],(long long)views[i]);
            }
            else{
                freq[creators[i]]={ids[i],views[i]};
                 id[creators[i]]=(long long)views[i];
                
            }
        }
        priority_queue<pair<long long,vector<string>>> pq;
        for(auto i:freq){
            pq.push({i.second.second,{i.first,i.second.first}});
        }
        vector<vector<string>> ans;
        long long prev=0;
        while(!pq.empty()){
            long long v=pq.top().first;
            if(v<prev)break;
           cout<<v<<" ";
            ans.push_back(pq.top().second);
            pq.pop();
            prev=v;
        }
        return ans;
    }
};

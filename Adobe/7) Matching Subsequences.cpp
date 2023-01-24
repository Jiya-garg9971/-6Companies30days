class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<int,vector<int>> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
        int cnt=0;
        for(auto i:words){
            int j=-1;bool found=true;
            for(int k=0;k<i.length();k++){
                if(mp.find(i[k])!=mp.end()){
                    auto lb=upper_bound(mp[i[k]].begin(),mp[i[k]].end(),j);
                    if(lb==mp[i[k]].end()){
                         found=false;
                        break;    
                    }
                    int idx=lb-mp[i[k]].begin();
                    j=mp[i[k]][idx];                    
                }
                else{
                    found=false;
                    break;
                }
            }
           if(found) cnt++;
        }
        return cnt;
    }
};

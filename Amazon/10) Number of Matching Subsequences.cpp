class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
        int cnt=0;
        for(auto i:words){
            string a=i;int k=-1;bool flag=true;
            for(auto j:i){
                if(mp.count(j)){
                    auto idx=upper_bound(mp[j].begin(),mp[j].end(),k);
                    if(idx==mp[j].end()){
                        flag=false;
                        break;
                    }
                    int n=idx-mp[j].begin();
                    k=mp[j][n];
                }
                else{
                    flag=false;
                    break;
                }
            }
           if(flag) {cnt++;cout<<a<<" ";}
        }
        return cnt;
    }
};

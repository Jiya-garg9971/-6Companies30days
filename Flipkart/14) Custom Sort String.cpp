class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        string ans="";
        for(auto i:order){
            if(mp.count(i)){
                 int t=mp[i];
                while(t--){
                    ans+=i;
               
                mp[i]--;}
            }
            if(mp[i]==0){
                mp.erase(i);
            }
        }
        for(auto i:mp){
            int t=i.second;
            while(t--)
            ans+=i.first;
        }
        return ans;
    }
};

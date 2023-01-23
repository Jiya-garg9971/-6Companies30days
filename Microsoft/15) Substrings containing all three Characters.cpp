/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        map<int,int> mp;
        int j=0;
        int n=s.length();
        int i=0,cnt=0;
        while(j<s.length()){
            mp[s[j]-'a']++;
            while(mp[0] and mp[1] and mp[2]){
                mp[s[i]-'a']--; i++;            
            }
            cnt+=i; 
            j++;
        }
        
        return cnt;
    
    }
};

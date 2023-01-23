/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
*/
class Solution {
public:
    string longestPrefix(string s) {
        int ans=0;
        long long int mod=1e9+9;
        long long int pwr=31;
        long long int p=1;
        long long int pref=0,suff=0;
        long long int n=s.length()-1;
        if(n==0 || n==-1)return "";        
        for(long long int i=0;i<n;i++){
            pref=pwr*pref+(s[i]-'a'+1);
            pref=pref%mod;  
            suff=suff+((s[n-i]-'a'+1)*p)%mod;
            suff=suff%mod;
            p=(pwr*p)%mod;    
            if(pref==suff) {       
                ans=i+1;
            }  
        }
        return s.substr(0,ans);
    }
};


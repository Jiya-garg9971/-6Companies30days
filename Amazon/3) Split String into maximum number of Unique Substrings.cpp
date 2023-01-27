class Solution {
public:
int mx=0;
void helper(string &s,int idx,set<string> &st){
    if(idx==s.length()){
        int n=st.size();
        mx=max(mx,n);
        return;
    }
    string a="";
    for(int i=idx;i<s.length();i++){
        a+=s[i];
        if(st.count(a)==0){
            st.insert(a);
            helper(s,i+1,st);
            st.erase(a);
        }
    }
}
    int maxUniqueSplit(string s) {
        set<string> st;
        int idx=0;
        int i=0,n=s.length();
        helper(s,0,st);
        return mx;        
    }
};

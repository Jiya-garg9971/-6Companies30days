class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        if(k>s.length())return false;
        for(int i=0;i<=s.length()-k;i++){
            st.insert(s.substr(i,k));
        }
        return st.size()==pow(2,k);
    }
};

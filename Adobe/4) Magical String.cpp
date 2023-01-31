class Solution {
public:
    int magicalString(int n) {
        int idx=2;
        string s="122";
        while(s.size()<n){
            int repeat=s[idx]-'0';
            char character=(s.back())^3; //3-last char
         
            int req=n-s.size();
           // repeat=min(repeat,req);
            s+=string(repeat,character);
            idx++;
        }
        return count(s.begin(),s.begin()+n,'1');
    }
};

class Solution {
public:
void helper(string s,int i,string t,vector<string> &ans,int dec){
    if(i==s.length()){
       t.pop_back();
       if(dec==4 and t.length()==s.length()+3) ans.push_back(t);
        return;
    }
    int num=0;
    int j=i;
    while(j<i+3 and j<s.length()){
        int newno=num*10+(s[j]-'0');
        if(newno<=255){
            num=newno;
            helper(s,j+1,t+to_string(num)+".",ans,dec+1);
           
        }
        else{
            break;
        }
        j++;
    }
}
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string t="";
        helper(s,0,t,ans,0);
        return ans;
    }
};

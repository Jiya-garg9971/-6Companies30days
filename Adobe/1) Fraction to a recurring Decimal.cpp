class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long num=(long long) numerator;
        long long den=(long long) denominator;
        long long int integer=num/den;
        string ans="";bool neg=false;
        if(num==0)return "0";
        ans+=to_string(integer);
        if(num<0 ^ den<0)neg=true;
        num=abs(num);
        den=abs(den);       
        unordered_map<long long int,int> idx;
        if(num%den==0)return ans;
        long long int i=0;
        string a="";
        ans+=".";
        while(num%den!=0){
            long long int rem=num%den;
            num=rem*10;
            cout<<num<<" ";
            a+=to_string(num/den);
            if(idx.find(num)==idx.end()){
                idx[num]=i;
            }
            else{
                cout<<idx[num]<<"-"<<i;
                if(idx[num])
                ans+=a.substr(0,idx[num])+"("+a.substr(idx[num],i-idx[num])+")";
                else{
                     ans+="("+a.substr(idx[num],i-idx[num])+")";
                }
                if(neg==true and integer==0){
                    ans="-"+ans;
                }
                break;
            }
            i++;   
        }       
        if(num%den==0){
           ans+=a;
              if(neg==true and integer==0){
                    ans="-"+ans;
                }
        }       
        return ans;
    }
};

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
       // return false;
       for(int i=2;i<=n;i++){
           int num=n;
           string val="";
            while(num>0){
               int rem=num%i;
               val+=to_string(rem);
                num/=i;
           }
           cout<<val<<endl;
           int k=val.size();
           for(int j=0;j<val.size()/2;j++){
               if(val[j]!=val[k-j-1])return false;
           }
       }  
       return true;
    }
};

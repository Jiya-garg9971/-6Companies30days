class Solution {
public:
    void prime(vector<int>&v,int n){
        //int j=0;//0-->nprime
        v[1]=0;
        for(int i=2;i*i<=n;i++){
            if(v[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    v[j]=0;
                    
                }
            }
        }
       return;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> p(right+1,1);
        prime(p,right);
        vector< int> ans;
        int diff=INT_MAX;int min1=-1,min2=-1;
        for(int i=left;i<=right;i++){
            if(p[i] and min1==-1){
                min1=i;}
            else if(p[i] and min2==-1){
                min2=i;
                if(diff>min2-min1){
                     cout<<min1<<" ,"<<min2<<" ";
                    ans={min1,min2};
                    diff=min2-min1;
                    
                }
                min1=i,min2=-1;
                
            } 
        }
        if(ans.size()==0){
            return {-1,-1};
        }
        cout<<endl;
        return ans;
    }//[1091,1093]
};

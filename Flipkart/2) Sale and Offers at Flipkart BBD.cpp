class Solution {
private:
    bool compare(vector<int>& a,vector<int>&i){
        for(int j=0;j<a.size();j++){
            if(a[j]<i[j]){
                return false;
            }
       }
       return true;
    }
    void subtract(vector<int>& needs,vector<int>&i){
        for(int k=0;k<needs.size();k++)
            needs[k]-=i[k]; 
        return;                   
    }
    void add(vector<int>& needs,vector<int>&i){
        for(int k=0;k<needs.size();k++)
            needs[k]+=i[k];    
        return ;               
    }
    int suball(vector<int> &needs,vector<int>&price){
        int cost=0;
        for(int k=0;k<needs.size();k++)
            cost+=needs[k]*price[k];  
        return cost;               
    }
    int helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,map<vector<int>,int>&dp){
        if(dp.count(needs))
          return dp[needs];
          int mx=suball(needs,price);
          
        for(auto i:special){
            if(compare(needs,i)){
                subtract(needs,i);
                mx=min(mx,i[needs.size()]+helper(price,special,needs,dp)); 
                add(needs,i);             
            }
        }
        return dp[needs]= mx;
    }
       
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
       map<vector<int>,int> dp;
           
        return  helper(price,special,needs,dp); ;
    }
};

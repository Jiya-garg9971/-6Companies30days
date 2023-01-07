/*
Q) On day 1, one person discovers a secret.
You are given an integer delay, which means that each person will share the secret with a new person every day, 
starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days
after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.
Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.
*/

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod=1e9+7;
        vector<long long int> dp(n+1,0);
        dp[1]=1;
        long long int total=0;
        long long int noofpeoplesharingsecret=0;
        for(int i=2;i<=n;i++){
            dp[i]=noofpeoplesharingsecret;
            long long int noofNewpeoplesharingsecret=0;
            if(i-delay>0){
                noofNewpeoplesharingsecret=dp[i-delay];
            }
            long long int noofpeopleforgettingsecret=0;
            if(i-forget>0){
                noofpeopleforgettingsecret=dp[i-forget];
            }
            dp[i]+=(noofNewpeoplesharingsecret-noofpeopleforgettingsecret+mod)%mod;
            noofpeoplesharingsecret+=(noofNewpeoplesharingsecret-noofpeopleforgettingsecret+mod)%mod;
        }
        for(int i=n-forget+1;i<=n;i++){
            total=(total+dp[i])%mod;
        }
        return total;
    }
};

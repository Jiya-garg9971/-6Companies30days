class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int mx=0;int j=0;
        int n=fruits.size();
        for(int i=0;i<n;i++){
            mp[fruits[i]]++;
            if(mp.size()<=2){
                cout<<i<<" ";
                mx=max(mx,i-j+1);
            }
            int n=mp.size();
            while(j<i and mp.size()>2){
                mp[fruits[j]]--;
                if(mp[fruits[j]]<=0){
                    mp.erase(fruits[j]);
                    n-=1;
                } j++;
                if(mp.size()<=2){
                    cout<<i<<" ";
                    mx=max(mx,i-j+1);
                }
               
            }
        }
        return mx;
    }
};

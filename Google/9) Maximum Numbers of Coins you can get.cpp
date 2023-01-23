class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int mycoins=0;
        sort(piles.begin(),piles.end());
        int st=0,end=piles.size()-1;
        while(st<end){
            st++;
            end-=2;
            mycoins+=piles[end+1];
        }
        return mycoins;
    }
};

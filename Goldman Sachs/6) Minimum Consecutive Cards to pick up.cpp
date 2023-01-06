/*
You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.
Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards.
If it is impossible to have matching cards, return -1.
*/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int> mp;
        int cnt=INT_MAX;
        int n=cards.size();
        for(int i=0;i<n;i++){
            if(mp.find(cards[i])!=mp.end()){
                cnt=min(cnt,i-mp[cards[i]]+1);
            }
            mp[cards[i]]=i;
        }
        if(cnt==INT_MAX){return -1;}
        return cnt;
        
    }
};

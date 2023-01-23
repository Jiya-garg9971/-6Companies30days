//Q3)Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

class Solution {
public:
    string getHint(string secret, string guess) {
        string ans="";
        int bull=0,nbull=0;
        map<int,int> sec;
        map<int,int> gues;
        for(int i=0;i<guess.length();i++){
            if(guess[i]==secret[i]){
                bull++;
            }
            else{
                sec[secret[i]]++;
                gues[guess[i]]++;
            }
        }
        for(auto i:sec){
            if(gues.count(i.first)){
                nbull+=min(i.second,gues[i.first]);
            }
        }
        ans+=to_string(bull)+'A'+to_string(nbull)+'B';
        return ans;
    }
};

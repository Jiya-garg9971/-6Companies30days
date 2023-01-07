/*
Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.
*/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> freq,vacancy;
        for(auto i:nums){
            freq[i]++;
        }
        for(auto i:nums){
            if(freq[i]==0){
                continue;
            }
            freq[i]--;
            if(vacancy.find(i-1)!=vacancy.end() and vacancy[i-1]>0){
                vacancy[i-1]--;
                vacancy[i]++;
            }
            else if(freq[i+1]!=0 and freq[i+2]!=0){
                freq[i+1]--;
                freq[i+2]--;
                vacancy[i+2]++;
            }
            else{
                return false;
            }
            
        }  
        return true;
    }
};

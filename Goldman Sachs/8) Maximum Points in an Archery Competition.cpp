/* Q) Maximum Points in an Archery Competition

*/



class Solution {
public:
    void helper(vector<int>&temp,int sum,int idx,vector<int> &alice,int &mx,vector<int> &bob,int arrows){
        if(idx==-1 || arrows==0){
            if(mx<sum){
                mx=sum;
                if(arrows>0){
                    temp[0]+=arrows;
                }
                bob=temp;
                cout<<sum<<" ";
            }
            return ;
        }
        
        int req=alice[idx]+1;
        if(req<=arrows){
            temp[idx]=req;
            helper(temp,sum+idx,idx-1,alice,mx,bob,arrows-req);
            temp[idx]=0;
        }
        helper(temp,sum,idx-1,alice,mx,bob,arrows);
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> temp(12,0);
        vector<int> bob;
        int mx=-1;
        helper(temp,0,11,aliceArrows,mx,bob,numArrows);
        return bob;
    }
};

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int mxleft=0;
        for(auto i:left){
            mxleft=max(mxleft,i);
        }
int mnright=INT_MAX;
        for(auto i:right){
            mnright=min(mnright,i);
        }
        return max(mxleft,n-mnright);
    }
};

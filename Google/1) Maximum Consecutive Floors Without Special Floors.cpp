class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int idx=lower_bound(special.begin(),special.end(),bottom)-special.begin();
        int ans=0;
        int st=bottom;
       // cout<<idx<<" ";
        int n=special.size();
        while(idx<n and special[idx]<=top){
            cout<<special[idx]-bottom<<" ";
            ans=max(special[idx]-bottom,ans);
            bottom=special[idx]+1;
            idx++;
        }
        if(bottom!=top)
        ans=max(top-bottom+1,ans);
        return ans;
    }
};

/* Q) Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

*/


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        map<int,int>x;
        int ans=1;
        for(auto i:points){
            x[i[0]]++;
            ans=max(ans,x[i[0]]);
        }
        map<int,int>y;
        for(auto i:points){
           y[i[1]]++;
            ans=max(ans,y[i[1]]);
        }
        for(int i=0;i<n;i++){
            map<double,int> mp;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                double ydiff=points[j][1]-points[i][1];
                double xdiff=points[j][0]-points[i][0];
                if(xdiff==0){continue;}
                double slope=ydiff/xdiff;
                mp[slope]++;
            }
            for(auto i:mp){
                cout<<i.first<<" ";
                ans=max(ans,i.second+1);
            }
        }

        
        return ans;
    }
};

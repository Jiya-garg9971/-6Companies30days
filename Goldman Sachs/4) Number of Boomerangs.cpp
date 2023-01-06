/*
Q) You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Return the number of boomerangs.
*/
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
       int cnt=0;int n=points.size();
      
       for(int i=0;i<n;i++){
            map<int,int> mp;
           for(int j=0;j<n;j++){
               int xdist=points[j][0]-points[i][0];
               int Ydist=points[j][1]-points[i][1];
               int d=pow(xdist,2)+pow(Ydist,2);
               
               mp[d]++;
           }
           for(auto i:mp){
               if(i.second>1){
                   int a=i.second;
                   cnt+=a*(a-1);
               }
           }
       }
       return cnt;
    }
};

/*Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).

 */
class Solution {
public:
int dist(vector<int>& a, vector<int>& b){
    return pow((b[1]-a[1]),2)+pow((b[0]-a[0]),2);
}
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int,int> mp;
        if(p1==p2 || p1==p3 || p1==p4 ||p2==p3 || p2==p4 ||p3==p4)return false;
        mp[dist(p1,p2)]++;
        mp[dist(p1,p3)]++;mp[dist(p1,p4)]++;
        mp[dist(p2,p3)]++;mp[dist(p2,p4)]++;
        mp[dist(p3,p4)]++;
        if(mp.size()!=2)return false;
        for(auto i:mp){
           return (i.second==2 || i.second==4);
        }
        return false;
        
    }
};

/*Q) Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).

Return true if all the rectangles together form an exact cover of a rectangular region.
*/

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //counting corners
        map<pair<int,int>,int> mp;
        for(auto i:rectangles){
            mp[{i[0],i[1]}]++;
            mp[{i[2],i[3]}]++;
            mp[{i[0],i[3]}]--;
            mp[{i[2],i[1]}]--;
        }
        int cnt=0;
        for(auto i:mp){
            if(i.second!=0){
                if(abs(i.second-0)!=1)return false;
                cnt++;
            }
        }
        return cnt==4;
    }
};

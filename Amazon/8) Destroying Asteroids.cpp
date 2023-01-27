class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        for(auto i:asteroids){
            if(mass<i){
                return false;
            }
            else{
                mass=mass+i;
            }
            if(mass>=1e5)return true;
        }
        return true;
    }
};

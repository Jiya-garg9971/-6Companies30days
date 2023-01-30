class Solution {
public:
double rad,x,y;
    Solution(double radius, double x_center, double y_center) {
        rad=(double)radius,x=x_center,y=y_center;
    }
    double random(){
        return (double)rand()/RAND_MAX;
    }
    vector<double> randPoint() {
        double random=sqrt((double)rand()/RAND_MAX)*rad;
        double theta=((double)rand()/RAND_MAX)*2.0*3.1415926535897932384;
        double xp=x+random*cos(theta);
        double yp=y+random*sin(theta);
        return {xp,yp};        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

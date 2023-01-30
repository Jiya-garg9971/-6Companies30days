class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negcnt=0;int maxneg=INT_MAX;
        long long sum=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0){negcnt++;}
                maxneg=min(maxneg,abs(matrix[i][j]));
            }
        }
        if(negcnt%2){
            return sum-2*maxneg;
        }
        return sum;
    }
};

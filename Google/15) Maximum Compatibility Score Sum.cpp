class Solution {
public:
int mx=0;
void helper(vector<vector<int>>& students,vector<vector<int>>& mentors,int idx){
        if(idx==students.size()){
             int c=0;
            for(int k=0;k<students.size();k++){            
                for(int a=0;a<students[0].size();a++){
                    if(students[k][a]==mentors[k][a])c++;
                }
            }
            mx=max(mx,c);
            return;
        }
        for(int i=idx;i<students.size();i++){
            swap(students[i],students[idx]);
            helper(students,mentors,idx+1);
             swap(students[i],students[idx]);
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        helper(students,mentors,0);
        return mx;
    }
};

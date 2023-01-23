/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/
class Solution {
public:
bool detectcycle(int i,vector<int> adj[],vector<bool>&visited,vector<bool>&stack){
    cout<<i<<" ";
    visited[i]=true;
    stack[i]=true;
    for(auto j:adj[i]){
        if(stack[j]==true){
            return true;
        }
        else if(!visited[j]){
            if(detectcycle(j,adj,visited,stack))
            return true;
        }        
    }
    stack[i]=false;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses+1];
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        //detect cycle in the directed graph
        vector<bool> visited(numCourses+1,false);
        vector<bool>stack(numCourses+1,false);
        bool ans=true;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
               if(detectcycle(i,adj,visited,stack)==true)return false;                
            }
        }
        return true;
        

    }
};

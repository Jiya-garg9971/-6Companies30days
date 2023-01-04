/*Q) Return the maximum net income Alice can have if she travels towards the optimal leaf node.
*/
class Solution {
public:
//first dfs to find steps from 0 to each other node and find leaf nodes
//second dfs to find parent of each node
//we can merge first two step in a single fn
//third to find money
    void dfs(int src,int parent,vector<int> &par,vector<int> &step,vector<int> adj[],int c){
        for(auto i:adj[src]){
            if(!step[i] and i!=parent){
                par[i]=src;
                step[i]=1+c;
                dfs(i,src,par,step,adj,c+1);
            }
        }
    }
   int maxprofit(int src,vector<int>&money,vector<int>&parent,vector<int> adj[]){
       int amt=money[src];
       int mx=INT_MIN;
       
       for(auto i:adj[src]){
           if(i!=parent[src]){
           mx=max(mx,maxprofit(i,money,parent,adj));
           }
       }
       if(mx==INT_MIN)return amt;
       return amt+mx;
   }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        //making the adjacency list
        vector<int> adj[n];{
            for(auto i:edges){
                adj[i[0]].push_back(i[1]);
                adj[i[1]].push_back(i[0]);
            }
        }
        //dfs to find parent;
        vector<int> step(n,0);
        vector<int> parent(n,0);
        dfs(0,-1,parent,step,adj,0);        
        int cnt=0;
        while(bob!=0){
            if(step[bob]>cnt){
                amount[bob]=0;
            }
            else if(step[bob]==cnt){
                amount[bob]/=2;
            }
            bob=parent[bob];
            cnt++;
        }
        for(auto i:amount){
            cout<<i<<" ";
        }

        return maxprofit(0,amount,parent,adj);
    }
};

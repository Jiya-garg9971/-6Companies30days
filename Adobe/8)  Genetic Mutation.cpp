class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int c=1;
        
        //adjacency list
      unordered_set<string> st(bank.begin(),bank.end());
        if(st.find(end)==st.end())
            return -1;
        queue<string> q;
        unordered_map<string,int> vist;
        q.push(start);
        vist[start]=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string b=q.front();
                q.pop();
                for(int i=0;i<8;i++){
                    string a=b;
                    for(int k=0;k<4;k++){
                        a[i]="ACGT"[k];
                        if(a==end){
                            cout<<a<<" ";
                            return c;
                        }
                        if(!vist[a] and st.find(a)!=st.end()){
                            q.push(a);
                            vist[a]=1;
                        }
                        
                    }
                }
            }
            c++;
        }
        cout<<"* ";
        return -1;
    }
};

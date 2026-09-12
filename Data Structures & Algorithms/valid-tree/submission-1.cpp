class Solution {
public:
    bool dfs(int i,int par,vector<bool>& visited,vector<int> adj[]){
        visited[i] = true;

        bool isCycle = false;
        for(auto it: adj[i]){
            if(!visited[it]){
                isCycle = isCycle || dfs(it,i,visited,adj);
            }
            else if(it!=par){
                isCycle = true;
                break;
            }
        }

        return isCycle;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];

        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> visited(n,false);

        bool valid=  !dfs(0,-1,visited,adj);

        if(!valid)return false;

        for(int i=0;i<n;i++){
            if(!visited[i])return false;
        }

        return true;


    }
};

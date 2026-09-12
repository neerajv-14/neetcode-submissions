class Solution {
public:
    int findPar(int node, vector<int>& parent){
        if(parent[node]==node)return node;

        // path compression
        return parent[node] = findPar(parent[node],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,bool> m;

        int k = edges.size();
        vector<int> parent(1001), rank(1001,0);
        for(int i=1;i<=1000;i++){
            parent[i] = i;
        }
        for(int i=0;i<k;i++){
            int x = edges[i][0], y = edges[i][1];

            int px = findPar(x,parent), py = findPar(y,parent);

            if(px==py)return edges[i];

            if(rank[px]==rank[py]){
                rank[px]++;
                parent[py] = parent[px];
            }
            else if(rank[px]>rank[py]){
                parent[py] = parent[px];
            }
            else{
                parent[px] = parent[py];
            }
        }

        return edges[k-1];
    }
};

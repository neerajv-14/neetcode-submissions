class Solution {
public:
    void bfs(queue<pair<int,int>>& q, vector<vector<int>>& visited,vector<vector<int>>& heights){

        int n = visited.size(), m = visited[0].size();

        int drow[4] = {-1,1,0,0}, dcol[4] = {0,0,-1,1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first , y = it.second;
            for(int z=0;z<4;z++){
                int nr = x + drow[z], nc = y + dcol[z];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && heights[nr][nc]>=heights[x][y]){
                    visited[nr][nc] = true;
                    q.push(make_pair(nr,nc));
                }
            }
        }

        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>>pacific(n,vector<int>(m, false)), atlantic(n,vector<int>(m,false));

        queue<pair<int,int>>pac, atl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    pac.push(make_pair(i,j));
                    pacific[i][j] = true;
                }

                if(i==n-1 || j==m-1){
                    atl.push(make_pair(i,j));
                    atlantic[i][j] = true;
                }
            }
        }

        bfs(pac,pacific,heights);

        bfs(atl,atlantic,heights);

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    vector<int> temp = {i,j};
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};

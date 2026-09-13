class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();

        int mx=0,my=0,mz=0;

        for(int i=0;i<n;i++){
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]){
                mx = max(mx, triplets[i][0]);
                my = max(my, triplets[i][1]);
                mz = max(mz, triplets[i][2]);
            }
        }

        if(mx==target[0] && my==target[1] && mz==target[2])return true;

        return false;
    }
};

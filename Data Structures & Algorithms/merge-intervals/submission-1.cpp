class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());

        vector<vector<int>>ans;

        ans.push_back(intervals[0]);

        int currEnd = ans[0][1],ptr=0;

        for(int i=1;i<n;i++){
            if(currEnd<intervals[i][0]){
                ans.push_back(intervals[i]);
                ptr++;
                currEnd = intervals[i][1];
            }
            else{

                currEnd = max(intervals[i][1],currEnd);
                ans[ptr][1] = currEnd;
            }
        }

        return ans;
    }
};

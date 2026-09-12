class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;

        int n = intervals.size();
    
        bool flag = false;
        int ptr=-1;
        int currEnd = -1;

        for(int i=0;i<n;i++){
            if(flag){
                if(currEnd<intervals[i][0]){
                    ans.push_back(intervals[i]);
                    currEnd = intervals[i][1];
                    ptr++;
                }
                else{
                    currEnd = max(intervals[i][1],currEnd);
                    ans[ptr][1] = currEnd;
                }
            }
            else{
                    if(intervals[i][0] > newInterval[1]){
                        ans.push_back(newInterval);
                        ans.push_back(intervals[i]);
                        currEnd = intervals[i][1];
                        ptr+=2;
                        flag = true;
                    }
                    else if(intervals[i][1]>=newInterval[0]){
                        vector<int> intV = {min(intervals[i][0],newInterval[0]), max(intervals[i][1],newInterval[1])};
                        ans.push_back(intV);
                        ptr++;
                        currEnd = ans[ptr][1];
                        flag = true;
                    }
                    else{
                        ans.push_back(intervals[i]);
                        ptr++;
                        currEnd = intervals[i][1];
                    }

            }
            
        }

        if(!flag){
            ans.push_back(newInterval);
        }

        return ans;
    }
};

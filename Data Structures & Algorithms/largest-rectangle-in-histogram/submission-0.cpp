class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nextSmaller(n,n), prevSmaller(n,-1);

        stack<int> s1,s2;

        s1.push(n-1);

        for(int i=n-2;i>=0;i--){
            while(!s1.empty() && heights[s1.top()]>=heights[i]){
                s1.pop();
            }

            if(!s1.empty())nextSmaller[i] = s1.top();

            s1.push(i);
        }

        s2.push(0);

        for(int i=1;i<n;i++){
            while(!s2.empty() && heights[s2.top()]>=heights[i]){
                s2.pop();
            }

            if(!s2.empty())prevSmaller[i] = s2.top();

            s2.push(i);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            int prev = prevSmaller[i], next = nextSmaller[i];
            ans = max(ans, heights[i]*(next-prev-1));
        }

        return ans;


    }
};

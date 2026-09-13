class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> dp1(n), dp2(n);
        int ans=0;
        for(int i=0;i<n-1;i++){
            int val=0;
            if(i>=2)val = dp1[i-2];

            int prev = 0;
            if(i>=1)prev = dp1[i-1];

            dp1[i] = max(prev, val + nums[i]);
            ans = max(ans,dp1[i]);
        }

        for(int i=1;i<n;i++){
            int val=0;
            if(i>=3)val = dp2[i-2];

            int prev = 0;
            if(i>=2)prev = dp2[i-1];

            dp2[i] = max(prev, val + nums[i]);
            ans = max(ans,dp2[i]);
        }

        return ans;
    }
};

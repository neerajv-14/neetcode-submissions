class Solution {
public: 
    int solve(vector<int>& nums,int i,vector<int>& dp){
        int n = nums.size();
        if(i==n-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int mini = 1e9;
        for(int k=1;k<=nums[i];k++){
            if(i+k<n)mini = min(1 + solve(nums,i+k,dp),mini);
        }

        return dp[i]=mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,dp);
    }
};

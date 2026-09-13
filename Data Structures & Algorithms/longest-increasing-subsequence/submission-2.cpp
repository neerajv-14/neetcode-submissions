class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // vector<int> dp(n,1);
        // int ans=1;
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i]>nums[j]){
        //             dp[i] = max(dp[i], 1 + dp[j]);
        //         }
        //     }
        //     ans = max(ans, dp[i]);
        // }

        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(temp.back()<nums[i]){
                temp.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }

        return temp.size();
    }
};

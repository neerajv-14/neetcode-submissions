class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;

        for(auto &x: nums){
            maxi = max(maxi,x);
        }

        if(maxi<=0)return maxi;

        int ans=0,sum=0;

        for(auto &x: nums){
            sum+=x;
            ans = max(ans,sum);
            if(sum<0)sum=0;
        }

        return ans;
    }
};

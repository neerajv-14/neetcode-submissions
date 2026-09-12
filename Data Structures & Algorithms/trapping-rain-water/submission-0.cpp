class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> lmaxi(n,0),rmaxi(n,0);
        int maxi =0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,height[i]);
            lmaxi[i] = maxi;
        }
        maxi =0;

        for(int i=n-1;i>=0;i--){
            maxi = max(maxi, height[i]);
            rmaxi[i] = maxi;
        }

        int ans=0;

        for(int i=1;i<n-1;i++){
            ans += min(rmaxi[i],lmaxi[i]) - height[i];
        }

        return ans;
    }
};

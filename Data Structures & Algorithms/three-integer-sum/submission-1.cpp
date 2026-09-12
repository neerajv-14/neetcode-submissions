class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());
        
        vector<vector<int>>ans;
        if(nums[0]>0)return ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int target = -1*nums[i];
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int  k = n-1;
                while(j<k){
                    
                    int sum = nums[j] + nums[k];
                    //cout << i << " "<< l << " "<< k << " " << sum << " "<< target << endl;
                    if(sum==target){
                        vector<int> temp = {nums[i],nums[j],nums[k]};
                        ans.push_back(temp);
                        break;
                    }
                    else if(sum>target){
                        k--;
                    }
                    else{
                        j++;
                    }
                }
            }

            
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int i=0,j=n-1;

        while(i<j){
            int sum = numbers[i]+numbers[j];
            if(sum==target){
                vector<int>ans;
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            else if(sum>target){
                j--;
            }
            else{
                i++;
            }
        }
    }
};

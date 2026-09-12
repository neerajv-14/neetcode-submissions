class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);

        ans[0] = 0;

        int si=1,ptr=1;

        while(ptr<=n){

            for(int i=0;i<si && ptr<=n;i++){
                ans[ptr] = 1 + ans[i];
                ptr++;
            }

            si*= 2;
        }

        return ans;
        

    }
};

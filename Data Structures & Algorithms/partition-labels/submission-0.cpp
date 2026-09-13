class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        unordered_map<int,int>last;

        for(int i=0;i<n;i++){
           
            last[s[i]]=i;
            
        }

        vector<int>ans;

        int start =0,end=0;

        for(int i=0;i<n;i++){
            end = max(end,last[s[i]]);

            if(end==i){
                ans.push_back(end-start+1);
                start = i+1;
                end=start;
            }
        }

        return ans;
    }
};

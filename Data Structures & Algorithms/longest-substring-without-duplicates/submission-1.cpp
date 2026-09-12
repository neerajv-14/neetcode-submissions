class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0,j=0,ans=0;
        unordered_map<char,int>m;
        while(j<n){
            if(m.find(s[j])==m.end()){
                m[s[j]]=j;
            }
            else{
                if(m[s[j]]>=i){
                    i = m[s[j]]+1;
                }
                m[s[j]]= j;
                
            }

            ans = max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};

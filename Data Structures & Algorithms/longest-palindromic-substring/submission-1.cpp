class Solution {
public:

    string longestPalindrome(string s) {
        
        int n = s.size();

        int ans=0, st;

        for(int i=0;i<n;i++){
            int j = i-1, k = i+1;

            int currAns=1;

            while(j>=0 && k<n && s[j]==s[k]){
                j--;
                k++;
                currAns+=2;
            }

            if(ans<currAns){
                ans = currAns;
                st = j+1;
            }

            j = i, k = i+1;
            currAns=0;
            while(j>=0 && k<n && s[j]==s[k]){
                currAns+=2;
                j--;
                k++;
            }

            if(ans<currAns){
                ans = currAns;
                st = j+1;
            }

        }

        return s.substr(st,ans);
    }
};

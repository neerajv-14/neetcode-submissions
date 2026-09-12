class Solution {
public:
    int characterReplacement(string s, int k) {
        // ABBBBA 
        int ans=0,n = s.size();
        // for(char ch='A';ch<='Z';ch++){
        //     int d = k;
        //     int i=0,j =0;

        //     while(j<n){
        //         if(s[j]!=ch){
        //             if(d>0){
        //                 d--;
        //             }
        //             else{
        //                 while(s[i]==ch)i++;
        //                 i++;
        //             }
        //         }
        //         ans = max(ans,j-i+1);
        //         j++;
        //     }
        // }
        int i=0,j=0;
        unordered_map<char,int>m;
        int maxF=0;
        while(j<n){
            m[s[j]]++;
            maxF = max(maxF,m[s[j]]);

            while((j-i+1) - maxF>k){
                m[s[i]]--;
                i++;
            }

            ans = max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int ans=INT_MAX;
        unordered_map<char,int>freq;

        for(auto &ch: t){
            freq[ch]++;
        }

        int si = freq.size(), currCounter=0;
        int shortestStart = -1;
        unordered_map<char,queue<int>>q;
        
        set<int> order;
        bool flag = false;
        for(int i=0;i<n;i++){
            if(freq.find(s[i])!=freq.end()){
                if(q[s[i]].size() == freq[s[i]]){
                    order.erase(q[s[i]].front());
                    order.insert(i);

                    q[s[i]].pop();
                    q[s[i]].push(i);
                }
                else{
                    order.insert(i);
                    q[s[i]].push(i);
                    if(q[s[i]].size() == freq[s[i]]){
                        currCounter++;
                    }
                }

                if(currCounter==si){
                    flag = true;
                }
            }

            if(flag){
                auto itStart = order.begin(), itEnd = order.end();
                itEnd--;
                int currAns = *itEnd - *itStart + 1;

                if(ans>currAns){
                    ans = currAns;
                    shortestStart = *itStart;
                }
            }
        }

        if(shortestStart==-1)return "";

        return s.substr(shortestStart,ans);

    }
};

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        stack<int>st,star;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]=='*'){
                star.push(i);
            }
            else{
                if(st.empty() && star.empty()){
                    return false;
                }
                else{
                    if(st.empty())star.pop();
                    else st.pop();
                }
            }
        }

        int k = st.size(), m = star.size();

        if(k>m)return false;
        while(!st.empty()){
            if(st.top()>star.top())return false;
            st.pop();
            star.pop();
        }
        return true;
    }
};

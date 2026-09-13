class Solution {
public:
    bool solve(string& s){
        int n = s.size(), leftMin=0,leftMax=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                leftMin++;
                leftMax++;
            }
            else if(s[i]==')'){
                leftMin--;
                leftMax--;
            }
            else{
                leftMin--;
                leftMax++;
            }

            if(leftMax<0){
                // too many )'s 
                return false;
            }
            // to consider cases like: **( 
            if(leftMin<0){
                /// essentially saying that extra * are put to empty.
                // this part is not about ). extra ) check is taken care by leftMax. if leftMax<0, 
                // then obviously leftMin<0.
                leftMin=0;
            }
        }

        return leftMin==0;
    }
    bool checkValidString(string s) {

        return solve(s);
        // int n = s.size();

        // stack<int>st,star;

        // for(int i=0;i<n;i++){
        //     if(s[i]=='('){
        //         st.push(i);
        //     }
        //     else if(s[i]=='*'){
        //         star.push(i);
        //     }
        //     else{
        //         if(st.empty() && star.empty()){
        //             return false;
        //         }
        //         else{
        //             if(st.empty())star.pop();
        //             else st.pop();
        //         }
        //     }
        // }

        // int k = st.size(), m = star.size();

        // if(k>m)return false;
        // while(!st.empty()){
        //     if(st.top()>star.top())return false;
        //     st.pop();
        //     star.pop();
        // }
        // return true;
    }
};

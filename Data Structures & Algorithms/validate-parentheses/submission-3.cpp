class Solution {
public:
    bool isValid(string s) {
        stack<char>checker;

        int n = s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')checker.push(s[i]);
            else if(s[i]==')'){
                if(checker.empty())return false;
                if(checker.top()!='(')return false;
                checker.pop();
            }
            else if(s[i]=='}'){
                if(checker.empty())return false;
                if(checker.top()!='{')return false;
                checker.pop();
            }
            else if(s[i]==']'){
                if(checker.empty())return false;
                if(checker.top()!='[')return false;
                checker.pop();
            }
        }
        
        return checker.empty();
    }
};

class Solution {
public:
    bool isValid(string s) {
        // follow only simple step
        if(s.size()==1) return false;
        stack<int> st;
       for(int i=0;i<s.size();i++){
           if(s[i]=='('||s[i]=='{'||s[i]=='[')
           st.push(s[i]);
           else{
            if(!st.empty()){
                if(s[i]==')'&&st.top()=='(')
                st.pop();
                else if(s[i]=='}'&&st.top()=='{')
                st.pop();
               else  if(s[i]==']'&&st.top()=='[')
                st.pop();
                else return false;
            }
            else return false;
           }
       }
       return st.empty();
    }
};
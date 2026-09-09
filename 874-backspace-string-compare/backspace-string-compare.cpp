class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st, st1;

        for(auto x : s) {
            if(x == '#') {
                if(!st.empty())
                    st.pop();
            }
            else {
                st.push(x);
            }
        }

        for(auto x : t) {
            if(x == '#') {
                if(!st1.empty())
                    st1.pop();
            }
            else {
                st1.push(x);
            }
        }

        return st == st1;
    }
};
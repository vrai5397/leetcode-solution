class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(auto x:s){
            if(x=='*'&&!st.empty()){
                st.pop();
            }
            else
            st.push(x);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
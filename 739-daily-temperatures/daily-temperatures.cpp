class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // yo have to save the index also
        stack<pair<int,int>> st;
        vector<int> ans(temperatures.size(),0);
        for(int i=temperatures.size()-1;i>=0;i--){
            while(!st.empty()&&temperatures[i]>=st.top().first)
            st.pop();
            if(!st.empty()&&st.top().first>=temperatures[i])
            ans[i]=st.top().second-i;
   st.push({temperatures[i],i});
        }
        return ans;
    }
};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
       for(auto x:tokens){
         if(x=="+"){
            int nums1=st.top();
            st.pop();
            int nums2=st.top();
            st.pop();
            st.push(nums1+nums2);
         }
         else if(x=="*"){
            int nums1=st.top();
            st.pop();
            int nums2=st.top();
            st.pop();
            st.push(nums1*nums2);
         }
           else if(x=="/"){
            int nums1=st.top();
            st.pop();
            int nums2=st.top();
            st.pop();
            st.push(nums2/nums1);
            
         }     
           else if(x=="-"){
            int nums1=st.top();
            st.pop();
            int nums2=st.top();
            st.pop();
            st.push(nums2-nums1);
         }
         else{
         int nums1=stoi(x);
         st.push(nums1);

          }
          
       }
       return st.top();
    }
};
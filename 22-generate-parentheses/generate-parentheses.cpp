class Solution {
public:
// lets solve the question with help of the backtracking
void solve(string& output,vector<string>& ans,int open,int close){
    // base case
   if(open==0 && close==0){
     ans.push_back(output);
     return;
   }
    // ek case ko solve karo
    if(open>0){
       output.push_back('(');
       solve(output,ans,open-1,close);
       output.pop_back();// back track
    }
    if(close>open){ 
          output.push_back(')');
       solve(output,ans,open,close-1);
       output.pop_back();// back track
    }
}
    vector<string> generateParenthesis(int n) {
         int close=n;
         int open=n;
         string output="";
         vector<string> ans;
         solve(output,ans,open,close);
         return ans;
    }
};

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
        return false;
        string ans=s;
        ans+=s;
        int j=0;
        int i=0;
     
      while(i<ans.size()){
        if(ans[i]==goal[j]){
            // we have to check
              int p=i;
            for(int k=j;k<goal.size();k++){

              
                if(ans[p]!=goal[k])
                break;

          else if(k==goal.size()-1&&ans[p]==goal[k])
            return true;

        p++;
            }
        }
        i++;
      }
      return false;
    }
};
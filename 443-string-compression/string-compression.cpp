class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int j=0;
        string ans="";
        while(j<chars.size()){
            if(chars[i]==chars[j])
            j++;
            else{
               if(j-i==1){
                  ans+=chars[i];
                  i=j;
               }
             else{
                ans+=chars[i];
                ans+=to_string(j-i);
                i=j;
             }
               
               
            }
        }
        if(j-i==1)
        ans+=chars[i];
        else{
        ans+=chars[i];
        ans+=to_string(j-i);
        }
    for(int i=0;i<ans.size();i++)
    chars[i]=ans[i];
        return ans.size();
    }
};
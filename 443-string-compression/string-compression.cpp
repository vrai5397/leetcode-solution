class Solution {
public:
    int compress(vector<char>& chars) {
      int i=0;
      int j=i;
      string st="";
      int count=0;
      while(j<chars.size()){
        if(chars[i]!=chars[j]){
             // group has been ended
             int count=j-i;
             if(count==1) st+=chars[i];
             else{
                st+=chars[i];
                st+=to_string(count);
             }
             i=j;
        }
        else{
            j++;
        }
      }

      count=j-i;
        if(count==1) st+=chars[i];
             else{
                st+=chars[i];
                st+=to_string(count);
             }

      
      for(int i=0;i<st.size();i++){
          chars[i]=st[i];
      }
      return st.size();
    }
};
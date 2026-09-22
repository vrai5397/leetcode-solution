class Solution {
public:
int start=0;
int maxlen=0;
void expand(string s,int i,int j){
    while(i>=0&&j<s.size()&&s[i]==s[j]){
        i--;
        j++;
         
    }
    
   if(j-i-1>maxlen){
    maxlen=j-i-1;
     start=i+1;
   }
}
    string longestPalindrome(string s) {
        // we have to expand around the center
        for(int i=0;i<s.size();i++){
            expand(s,i,i+1);
            expand(s,i,i);
        }
        return s.substr(start,maxlen);
    }
};
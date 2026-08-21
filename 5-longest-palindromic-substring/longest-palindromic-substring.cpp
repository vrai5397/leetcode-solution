class Solution {
public:
int start=0;
int maxlen=0;
     void expand(string& s,int left,int right){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            left--;
            right++;
        }
        int len=right-left-1;
        if(len>maxlen){
            maxlen=len;
            start=left+1;
        }
     }
    string longestPalindrome(string s) {
        //ya to even len ki palindrome ban sakta hai
        // ya to odd len ki palindrome ban sakta hai
        // we have to check for each char
        for(int i=0;i<s.size();i++){
            // odd
            // even
            expand(s,i,i);
            expand(s,i,i+1);
        }
        return s.substr(start,maxlen);
    }
};
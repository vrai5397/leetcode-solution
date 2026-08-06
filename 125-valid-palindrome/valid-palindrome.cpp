class Solution {
public:
    bool isPalindrome(string s) {
        // check for valid palindrome
        // check for uppercase
        string st="";
        for(int i=0;i<s.size();i++){
             char ch=s[i];
             if(isupper(ch)){
                ch=tolower(ch);
             }
             if(isalnum(ch))
             st+=ch;
        }
        int i=0;
        int j=st.size()-1;
        while(i<j){
            if(st[i]!=st[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
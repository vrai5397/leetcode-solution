class Solution {
public:
bool check(string& s,int left,int right){
    while(left<right){
        if(s[left]!=s[right])
        return false;
          left++;
            right--;
    }
    return true;
}
    bool validPalindrome(string s) {
        // brute froce
        int left=0;
        int right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right]){
                // delete left char
                // delete right char

                return check(s,left+1,right)||check(s,left,right-1);
            }
            left++;
            right--;
        }
        return true;
    }
};
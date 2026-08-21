class Solution {
public:
// expand arount centre
int count=0;
void expand(string& s,int left,int right){
    while(left>=0&&right<s.size()&&s[left]==s[right]){
        left--;
        right++;
        count++;
    }
}
    int countSubstrings(string s) {
        for(int i=0;i<s.size();i++){
            // even 
            // odd
            expand(s,i,i);
            expand(s,i,i+1);
        }
        return count;
    }
};
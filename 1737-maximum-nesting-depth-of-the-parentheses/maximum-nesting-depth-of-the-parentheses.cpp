class Solution {
public:
    int maxDepth(string s) {
        int left=0;
        int right=0;
        if(s[0]=='(')
        left+=1;
        int maxdepth=0;
        for(int i=1;i<s.size();i++){
            int depth=left-right;
            maxdepth=max(maxdepth,depth);
            if(s[i]=='(')
            left++;
            if(s[i]==')')
            right++;
        }
        return maxdepth;
    }
};
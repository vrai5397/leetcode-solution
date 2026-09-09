class Solution {
public:
    bool judgeCircle(string moves) {
        int right=0;
        int up=0;
        for(auto x:moves){
            if(x=='R')
            right++;
            else if(x=='U')
            up++;
            else if(x=='L')
            right--;
            else 
            up--;
        }
        if(up==0&&right==0)
        return true;
        return false;
    }
};
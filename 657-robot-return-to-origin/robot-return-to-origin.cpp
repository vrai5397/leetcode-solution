class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0;
        int j=0;
        for(auto x:moves){
             if(x=='U')
                i=i-1;
             
             else if(x=='D')
             i=i+1;
             else if(x=='L')
             j=j-1;

             else
             j=j+1;
              
              
        }
        if(i==0&&j==0)
        return true;
        else
        return false;
    }
};
class Solution {
public:
    int balancedStringSplit(string s) {
        // we can break ther sting in how many balaced pieces
        int balanced=0;
        int count=0;
        for(auto x:s){
           if(x=='R')
           balanced++;
           if(x=='L')
           balanced--;
           if(balanced==0)
           count++;
        }
return count;
    }
};
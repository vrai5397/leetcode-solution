class Solution {
public:
    int maxOperations(string s) {
        int ones=0;
        int operation=0;
        int i=0;
        int n=s.size();
       while(i<n){
        if(s[i]=='0'){
            operation+=ones;
            while(i<n&&s[i]=='0'){
                i++;
            }
        }
        else{
            ones+=1;
            i++;
        }
        
       }
       return operation;
    }
};
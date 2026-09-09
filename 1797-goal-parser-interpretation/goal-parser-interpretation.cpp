class Solution {
public:
    string interpret(string command) {
        //
        string ans="";
        int i=0;
        while(i<command.size()){
       
            if(command[i]=='('&&command[i+1]=='a'){
                // al
                ans+="al";
                i+=4;
            }
            else if(command[i]=='('&&command[i+1]==')'){
                ans+='o';
                i+=2;
            }
            else{
            ans+='G';
            i++;
            }
           
        }
        return ans;
    }
};
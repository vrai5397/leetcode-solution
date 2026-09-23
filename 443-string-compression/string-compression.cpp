class Solution {
public:
    int compress(vector<char>& chars) {
        // we can use read and write;
        int n=chars.size();
        int read=0;
        int write=0;
        while(read<n){
            int count=0;
            char ch=chars[read];
            while(read<n&&chars[read]==ch){
                read++;
                count++;
            }
            if(count>1){
                chars[write++]=ch;
                string num=to_string(count);
                for(auto x:num)
                chars[write++]=x;

            }
            else
            chars[write++]=ch;
        }
        return write;
    }
};
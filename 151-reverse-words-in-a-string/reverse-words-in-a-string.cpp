class Solution {
public:
    string reverseWords(string s) {
        // break the string on the basis of space
        //fit the word in reverse order
        stringstream ss(s);
        vector<string> arr;
        string word;
        while(ss>>word){
            arr.push_back(word);
        }
        string ans="";
        for(int i=arr.size()-1;i>=0;i--){
            ans+=arr[i];
            if(i!=0)
            ans+=" ";
        }
        return ans;
    }
};
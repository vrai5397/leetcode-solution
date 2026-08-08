class Solution {
public:
bool isvowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    return true;

    return false;
}
    int maxVowels(string s, int k) {
        // classic sliding window problem
        int i=0;
        int j=0;
        int count=0;
        int maxcount=0;
     while(j<s.size()){
        if(isvowel(s[j]))
        count++;
        while(j-i+1>k){
            if(isvowel(s[i]))
            count--;
            i++;
        }

        if(j-i+1==k){
          maxcount=max(maxcount,count);
        }
        j++;
     }
     return maxcount;
    }
};
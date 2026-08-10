class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // we have to find subarray with 2 diff number
        if(fruits.size()==1) return fruits.size();
        int i=0;
        int j=i;
        unordered_map<int,int> mp;
        int maxcount=0;
        while(j<fruits.size()){
            mp[fruits[j]]++;
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)
                mp.erase(fruits[i]);
                i++;
            }
           
            maxcount=max(maxcount,j-i+1);
            j++;
        }
        return maxcount;
    }
};
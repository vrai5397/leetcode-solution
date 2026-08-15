class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       // n+1 point
       vector<int> alt(gain.size()+1,0);
       int maxalt=alt[0];
       for(int i=1;i<alt.size();i++){
           alt[i]=alt[i-1]+gain[i-1];
           maxalt=max(maxalt,alt[i]);
       }
       return maxalt;
    }
};
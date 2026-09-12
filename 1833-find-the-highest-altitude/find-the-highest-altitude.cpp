class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt=0;
        int maxi=0;
        for(auto x:gain){
          
            alt+=x;
               maxi=max(alt,maxi);
           
        }
        return maxi;
    }
};
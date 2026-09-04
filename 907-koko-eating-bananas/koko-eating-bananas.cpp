class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // int hi=max of piles
        // lo=1
        int hi=INT_MIN;
        for(int i=0;i<piles.size();i++)
        hi=max(hi,piles[i]);

        int lo=1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            long long hours=0;
            for(auto x:piles){
                // mid is speed
               if(x%mid!=0){
                  hours+=x/mid;
                  hours++;
               }
               else
               hours+=x/mid;
            }
            if(hours<=h)
                hi=mid-1;
            else
            lo=mid+1;

        }
return lo;
    }
};
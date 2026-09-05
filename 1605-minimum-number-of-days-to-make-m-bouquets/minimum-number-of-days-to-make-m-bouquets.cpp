class Solution {
public:
bool canWeMake(vector<int>&bloomDay,int m,int k,int mid){
    int boq=0;
    int flower=0;
    for(int j=0;j<bloomDay.size();j++){
        if(bloomDay[j]<=mid){
            // can be used
            flower++;
                 if (flower == k) {
                    boq++;
                    flower = 0;   // start looking for next bouquet

                    if (boq >= m)
                        return true;
                }
        }
        else{
            flower=0;
        }
    }
    return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
              if ((long long)m * k > bloomDay.size())
            return -1;

        int lo = *min_element(bloomDay.begin(), bloomDay.end());
      int hi = *max_element(bloomDay.begin(), bloomDay.end());
      while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(canWeMake(bloomDay,m,k,mid)){
            // fewer days
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
      }
      return lo;
    }
};
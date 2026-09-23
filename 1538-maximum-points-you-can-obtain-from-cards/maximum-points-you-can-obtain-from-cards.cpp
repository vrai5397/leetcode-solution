class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int totalsum=0;
        for(auto x:arr){
            totalsum+=x;
        }
        int k1=arr.size()-k;
        int i=0;
        int j=0;
        int sum=0;
        int minsum=INT_MAX;
        while(j<arr.size()){
           sum+=arr[j];
           while(j-i+1>k1){
             sum-=arr[i];
             i++;
           }
           if(j-i+1==k1)
           minsum=min(minsum,sum);
           j++;
        }
        return totalsum-minsum;
    }
};
class Solution {
public:
bool present(vector<int>& arr,int target){
    int lo=0;
    int hi=arr.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==target)
        return true;
        else if(arr[mid]>target)
        hi=mid-1;
        else
        lo=mid+1;
    }
    return false;
}
    int findKthPositive(vector<int>& arr, int k) {
       
       int lo=1;
        int hi=arr[arr.size()-1]+k;
        
         int p=0;
        for(int i=lo;i<=hi;i++){
            
             if(!present(arr,i)){
             p++;
                if(p==k)
             return i;
             }
           
        }
        return -1;
    }
};
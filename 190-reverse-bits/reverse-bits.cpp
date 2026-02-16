class Solution {
public:
    int reverseBits(int n) {
        vector<int> arr(32,0);
       
    int i=0;
    while(n!=0){
       
        int r=n%2;
        arr[i]=r;
        i++;
        n=n/2;
    }
unsigned int num=0;
  for(int i=0;i<arr.size();i++){
     num=num*2+arr[i];
  }
  return num; 
    }
};

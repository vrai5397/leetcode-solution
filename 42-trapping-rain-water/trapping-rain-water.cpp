class Solution {
public:
vector<int> getleftmax(vector<int>&height){
    vector<int>ans(height.size(),0);
   ans[0]=height[0];
    for(int i=1;i<height.size();i++){
        ans[i]=max(ans[i-1],height[i]);
    }
    return ans;
}
vector<int> getrightmax(vector<int>&height){
    vector<int>ans(height.size(),0);
    int n=height.size();
   ans[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        ans[i]=max(ans[i+1],height[i]);
    }
    return ans;
}
    int trap(vector<int>& height) {
        int ans=0;
        vector<int> leftmax=getleftmax(height);
        vector<int> rightmax=getrightmax(height);
        for(int i=0;i<height.size();i++){
            int water=min(leftmax[i],rightmax[i])-height[i];
            ans+=water;
        }
        return ans;
    }
};
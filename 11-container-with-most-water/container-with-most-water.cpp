class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxarea=INT_MIN;
        while(i<j){
            int h=min(height[i],height[j]);
            int area=h*(j-i);
            maxarea=max(area,maxarea);
            if(height[i]<height[j])
            i++;
            else if(height[i]==height[j]){
                i++;
                j--;
            }
            else
            j--;
        }
        return maxarea;
    }
};
class Solution {
public:
int solve(vector<int>& prices,int i,int mini){
    // base case
    if(i>=prices.size())
    return 0;
   int selltoday=prices[i]-mini;
   mini=min(mini,prices[i]);
   int sellater=solve(prices,i+1,mini);

   return max(selltoday,sellater);
    
}
    int maxProfit(vector<int>& prices) {
        return solve(prices,0,prices[0]);
    }
};
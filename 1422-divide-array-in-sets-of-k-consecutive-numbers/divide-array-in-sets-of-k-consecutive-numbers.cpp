class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>
       ,greater<pair<int,int>>> pq;
       unordered_map<int,int> mp;
       for(auto x:hand){
          mp[x]++;
       }
       for(auto x:mp){
        pq.push({x.first,x.second});
       }
       while(!pq.empty()){
         // we consider consecutive honge
         vector<pair<int,int>> temp;
         int prev=-1;
          for(int i=0;i<k;i++){
            if(!pq.empty()){
                // we have too add consecutive case
              auto x=pq.top();
              pq.pop();
               if(i > 0 && x.first != prev + 1)
            return false;

        prev = x.first;
              temp.push_back({x.first,x.second-1});
            }
              else return false;
          }
          
          for(auto x:temp){
            if(x.second>0)
             pq.push({x.first,x.second});
          }
       }
       return true;
    }
};
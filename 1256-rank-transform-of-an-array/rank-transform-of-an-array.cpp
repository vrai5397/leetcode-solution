class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // we we push value index wise
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        int i=1;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            arr[x.second]=i;
            if(pq.top().first!=x.first)
            i++;
        }
        return arr;
    }
};
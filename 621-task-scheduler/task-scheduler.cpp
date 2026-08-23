class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
     
       int time=0;
       vector<int> freq(26,0);
       for(int i=0;i<tasks.size();i++){
          freq[tasks[i]-'A']++;
       }
       priority_queue<int> pq;
       for(auto x:freq){
        if(x>0)
        pq.push(x);
       }
       while(!pq.empty()){
        // pick n+1 task
        // after that we can use task with max freq
        vector<int> temp;
        for(int i=1;i<=n+1;i++){
            if(!pq.empty()){
                int fre=pq.top();
                pq.pop();
                fre--;
                 temp.push_back(fre);
            }
        }
        for(auto x:temp){
            if(x>0)
            pq.push(x);
        }
        if(pq.empty())
         time+=temp.size();
         else
         time+=n+1;
       }
        return time;
    }
};
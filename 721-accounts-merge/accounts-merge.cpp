class Solution {
public:
class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if(node == parent[node]) 
            return node;
        return parent[node] = findUPar(parent[node]);
    }

   
    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       // very good question
       unordered_map<string,int> mapmailnode;
       DisjointSet ds(accounts.size());
       for(int i=0;i<accounts.size();i++){
        for(int j=1;j<accounts[i].size();j++){
            //first we will do mapping
            string mail=accounts[i][j];
             if(mapmailnode.find(mail)==mapmailnode.end()){
                // not in map
                mapmailnode[mail]=i;
             }
             else{
                ds.unionBySize(i,mapmailnode[mail]);
             }
        }
    }

    // now we have to place mail to their ultimate parent
     vector<vector<string>> mergemail(accounts.size());
      for(auto x:mapmailnode){
          string mail=x.first;
          int node=x.second;
          int parent=ds.findUPar(node);
           mergemail[parent].push_back(mail);

      }
      vector<vector<string>> ans;
      for(int i=0;i<accounts.size();i++){
          if(mergemail[i].size()==0) continue;
          sort(mergemail[i].begin(),mergemail[i].end());
          vector<string> temp;
          temp.push_back(accounts[i][0]); // name
          for(auto it:mergemail[i])
          temp.push_back(it);

          ans.push_back(temp);

      }

      return ans;
    }
};
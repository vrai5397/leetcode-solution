class Solution {
public:
 class DisjointSet {
    public:
        vector<int> parent, size;

        DisjointSet(int n) {
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for(int i = 1; i <= n; i++)
                parent[i] = i;
        }

        int FindUPar(int node) {
            if(node == parent[node]) return node;
            return parent[node] = FindUPar(parent[node]);
        }

        void UnionBySize(int u, int v) {
            int pu = FindUPar(u);
            int pv = FindUPar(v);
            if(pu == pv) return;

            if(size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
    };


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();

        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1)
                 ds.UnionBySize(i+1,j+1);
                 
            }
        }

        int count=0;
        for(int i=1;i<=n;i++){
            if(ds.FindUPar(i)==i)
             count++;
        }

        return count;
    }
};
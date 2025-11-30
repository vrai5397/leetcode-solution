class Solution {
public:
class DisjointSet {
    public:
        vector<int> parent, size;

        DisjointSet(int n) {
            parent.resize(n);
            size.resize(n , 1);
            for(int i = 0; i < n; i++)
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        // find the number of edges
        int edges=connections.size();
        if(edges<n-1) return -1;
            DisjointSet ds(n);
            for(auto x:connections){
                int u=x[0];
                int v=x[1];
                ds.UnionBySize(u,v);

            }
            int count=0;
            for(int i=0;i<n;i++){
               if(ds.FindUPar(i)==i)
               count++;
            }

            return count-1;
        
    }
};
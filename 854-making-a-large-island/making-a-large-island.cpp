class Solution {
public:

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++)
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
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet ds(n*n);

    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};

    // Step 1: Connect all 1's
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            if(grid[row][col] == 0) continue;

            int node = row*n + col;

            for(int k=0;k<4;k++){
                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                    int adj = nr*n + nc;
                    ds.unionBySize(node, adj);
                }
            }
        }
    }

    int ans = 0;

    // Step 2: For every 0, try to flip it
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            if(grid[row][col] == 1) continue;

            unordered_set<int> comp;

            for(int k=0;k<4;k++){
                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                    int parent = ds.findUPar(nr*n + nc);
                    comp.insert(parent);
                }
            }

            int curr = 1;  // flipping current zero
            for(int p : comp)
                curr += ds.size[p];

            ans = max(ans, curr);
        }
    }

    // If no zero found → grid is all ones
    if(ans == 0) return n*n;

    return ans;
}

};

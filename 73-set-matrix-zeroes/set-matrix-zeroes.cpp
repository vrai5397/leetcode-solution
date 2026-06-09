class Solution {
public:
void setzero(vector<vector<int>>& matrix,int i,int j){
 
     int r=matrix.size();
    int c=matrix[0].size();
    for(int k=0;k<c;k++){
        matrix[i][k]=0;
    }
     for(int k=0;k<r;k++){
        matrix[k][j]=0;
    }
}
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,pair<int,int>> mp;
        int r=matrix.size();
        int c=matrix[0].size();
        int x=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
          mp.insert(make_pair(x, make_pair(i, j)));
          x++;
                }
            }
        }
        for(auto x:mp){
          setzero(matrix,x.second.first,x.second.second);
        }
    }
};
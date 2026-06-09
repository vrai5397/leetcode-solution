class Solution {
public:
void setzero(vector<vector<int>>& matrix1,int i,int j){
    int r=matrix1.size();
    int c=matrix1[0].size();
    // row
   for(int k=0;k<c;k++)
   matrix1[i][k]=0;
   // col
   for(int k=0;k<r;k++ )
   matrix1[k][j]=0;
}
    void setZeroes(vector<vector<int>>& matrix) {
       // brute force 
       int r=matrix.size();
       int c=matrix[0].size();
       vector<vector<int>> matrix1(r,vector<int>(c,0));
       for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            matrix1[i][j]=matrix[i][j];
        }
       }
       for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j]==0){
                setzero(matrix1,i,j);
            }
        }
       }
        for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            matrix[i][j]=matrix1[i][j];
        }
       }
    }
};
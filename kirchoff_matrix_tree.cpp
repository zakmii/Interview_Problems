#include<bits/stdc++.h>

class KMT{ //Kirchoff's Matrix Tree
  int n;
  vector<vector<int>> mat;
  vector<vector<int>> sub_mat; //mat*
  public:
    
    KMT(vector<vector<int>> &adjMatrix,int n){ //adjacency matrix
        this->n=n;
        this->mat=adjMatrix;
        
        //Constructing the Laplacian Matrix
        
        vector<int> inDegree(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adjMatrix[i][j]==1){
                    inDegree[i]++;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            mat[i][i]=inDegree[i]; //putting inDegree as Diagonal 
        }
        
        // Replacing all 1 in the matrix which are not present on primary diagonal with -1
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
            {
                if ((i != j) && mat[i][j] == 1)
                {
                    mat[i][j] = -1;
                }

            }
        }
      
        //now deleting any 1 row and 1 column
        //in this case row 1 and column 1
        
        //making new matrix for that
        this->sub_mat.resize(n-1, vector<int>(n-1));
        
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                this->sub_mat[i-1][j-1]=mat[i][j];
            }
        }

    }
    
    int totalNumberOfSpanningTrees(){
        return det(sub_mat);
    }

   // determinant of a N X N matrix
    int det(vector<vector<int>> &mat){
        int sum=0;
        
        int row_size=mat.size();
        int column_size=mat.size();
        
        vector<vector<int>> minorMatrix(row_size-1,vector<int> (column_size-1,0));
        int row_minorMatrix, column_minorMatrix;
        int firstrow_columnindex;
        
        
        if(row_size==1){
            return mat[0][0];
        }
        if(row_size==2){
            return (mat[0][0]*mat[1][1]-mat[1][0]*mat[0][1]);
        }
        
        int row,column;

        // exclude first row and current column
        for(firstrow_columnindex = 0; firstrow_columnindex < row_size;
                firstrow_columnindex++) {

            row_minorMatrix = 0;

            for(row = 1; row < row_size; row++) {

                column_minorMatrix = 0;

                for(column = 0; column < column_size; column++) {
                    if (column == firstrow_columnindex){
                        continue;
                    }
                    else{
                        minorMatrix[row_minorMatrix][column_minorMatrix] = mat[row][column];
                    }

                    column_minorMatrix++;
                }

                row_minorMatrix++;
            }

            if (firstrow_columnindex % 2 == 0){
                sum += mat[0][firstrow_columnindex] * det(minorMatrix);
            }
            else{
                sum -= mat[0][firstrow_columnindex] * det(minorMatrix);
            }

        }

        return sum;
    }
};
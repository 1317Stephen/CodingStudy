/*
 * < Cracking The Coding Interview 6/E >
 * Problem #1.8 Exchange i-th row and j-th column values to zero if the element in (i,j) is zero
 * 
 * Author: YeEun Ko
 * >> Not Yet Better Solution: Bit Vector
 */
#include<iostream>
#include<utility>
#include<vector>

using namespace std;
int** makeMarix(int size);
void printMarix(int **matrix, int size);
void makeRowColumnZero(int **matrix, const int  size);

const int SIZE=5;

int main()
{
    int **matrix=makeMarix(SIZE);
    printMarix(matrix, SIZE);
    makeRowColumnZero(matrix, SIZE);
    cout<<"after\n";
    printMarix(matrix, SIZE);
    return 0;
}

void makeRowColumnZero(int **matrix, const int  size)
{
    int i,iRow,iColumn;
    bool *isZeroRow;
    bool *isZeroColumn;
    isZeroRow = (bool*)malloc(sizeof(bool)*size);
    isZeroColumn = (bool*)malloc(sizeof(bool)*size);
    for(i=0; i<size; i++)
    {
        isZeroRow[i]=false;
        isZeroColumn[i]=false;
    }

    for(iRow=0; iRow<size; iRow++)
    {
        for(iColumn=0; iColumn<size; iColumn++)
        {
            if(matrix[iRow][iColumn]==0)
            {
                isZeroRow[iRow]=true;
                isZeroColumn[iColumn]=true;
            }
        }
    }

    for(i=0; i<size; i++)
    {
        if(isZeroRow[i])
        {
            for(iColumn=0; iColumn<size; iColumn++)
            {
                matrix[i][iColumn]=0;
            }
        }
        if(isZeroColumn[i])
        {
            for(iRow=0; iRow<size; iRow++)
            {
                matrix[iRow][i]=0;
            }
        }
        
    }

    
}

int** makeMarix(int size)
{
    int i=0,j=0;
    int **matrix;
    matrix=(int**)malloc(sizeof(int*)*size);
    for(i=0; i<size; i++)
    {
        matrix[i]=(int*)malloc(sizeof(int)*size);
        for(j=0; j<size; j++)
        {
            if( (i*size+j)%10==1 )
            {
                matrix[i][j]=0;
            }
            else
            {
                matrix[i][j]=i*size+j;
            }
            
            
        }
    }
    return matrix;
}

void printMarix(int **matrix, int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            printf(" %3d ", matrix[i][j]);
            // cout<<matrix[i][j];
        }
        cout<<"\n";
    }

}
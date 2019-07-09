/*
 * BaekJoon #16967. Restore the Matrix
 * 
 * https://www.acmicpc.net/problem/16967
 * 
 * Author: YeEun Ko
 */

#include<iostream>
#include<string.h>

using namespace std;

int** getMatrix(int row, int column);
void setMatrix(int **matrix, int row, int column);
void printMarix(int **matrix, int row, int column);

int** getOriginMatrix(int **matrix, int originRow, int originColumn, int X, int Y); //->fail
void printOriginMatrix(int **matrix, int originRow, int originColumn, int X, int Y); 

int main()
{
    int H,W, X, Y;
    int **matrix;
    int **origin;
    cin>>H>>W>>X>>Y;

    matrix=getMatrix(H+X, W+Y);
    setMatrix(matrix, H+X, W+Y);

    // printMarix(matrix, H+X, W+Y);

    // cout<<"\n";
    // origin = getOriginMatrix(matrix, H, W, X, Y);
    // printMarix(origin, H, W);

    printOriginMatrix(matrix, H, W, X, Y);

    return 0;
}

void printOriginMatrix(int **matrix, int originRow, int originColumn, int X, int Y)
{
    int i,j;
    int iMinus=0, jMinus=0;
    for(i=0; i<originRow; i++)
    {
        for(j=0; j<originColumn; j++)
        {
            if(i>=X && j>=Y)
            {
                matrix[i][j]-=matrix[i-X][j-Y];
            }
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** getOriginMatrix(int **matrix, int originRow, int originColumn, int X, int Y)
{
    int i,j;
    int **origin=getMatrix(originRow, originColumn);
    for(i=0; i<originRow; i++)
    {
        for(j=0; j<originColumn; j++)
        {
            if(i>=X && j>=Y && i<originRow-1 && j<originColumn-1)
            {
                origin[i][j] = matrix[i][j] - matrix[i-X][j-Y];
            }
            else
            {
                // origin[i][j] = matrix[i][j];
                origin[i][j] = ( (matrix[i][j]<matrix[i+X][j+Y]) ? matrix[i][j] : matrix[i+X][j+Y] );
            }
            

        }

    }
    return origin;
}

void printMarix(int **matrix, int row, int column)
{
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        cout<<"\n";
    }

}

int** getMatrix(int row, int column)
{
    int i;
    int **matrix;

    matrix = (int**)malloc(sizeof(int*)*row);
    for(i=0; i<row; i++)
    {
        matrix[i]=(int*)malloc(sizeof(int)*column);
        memset(matrix[i], 0,sizeof(int*)*column );
    }
    return matrix;
}
void setMatrix(int **matrix, int row, int column)
{
    int i,j;
    

    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            cin>>matrix[i][j];
        }

    }
    
}
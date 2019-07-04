/*
 * < Cracking The Coding Interview 6/E >
 * Problem #1.7 Rotate Matrix 90 degrees(without addtional space for matrix)
 *      Matrix is represented in 4 byte(int, long, float)
 * 
 * Author: YeEun Ko
 * 
 */
#include<iostream>
#include<algorithm>

using namespace std;

int** makeMarix(int size);
void printMarix(int **matrix, int size);
void rotateMatrix(int **matrix, int size);

int SIZE=3;
int main()
{
    int **matrix=makeMarix(SIZE);
    cout<<"Before"<<"\n";
    printMarix(matrix,SIZE);
    rotateMatrix(matrix, SIZE);

    cout<<"After"<<"\n";
    printMarix(matrix,SIZE);

    return 0;
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
            matrix[i][j]=i*size+j;
        }
    }
    return matrix;
}


void rotateMatrix(int **matrix, int size)
{
    int i=0, j=0;
    //행렬 전치(Transpose Matrix)
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(i>j)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    //Flip Matrix horizontally(left to right)
    for(i=0; i<size; i++)
    {
        for(j=0; j<size/2; j++)
        {
            swap(matrix[i][j], matrix[i][size-1-j]);
        }
    }
}
void printMarix(int **matrix, int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            cout<<matrix[i][j];
        }
        cout<<"\n";
    }

}
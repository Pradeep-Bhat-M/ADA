#include <iostream>



void matrixMul(int **a, int **b, int **result, int row, int common, int col)
{
    for(int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)                         // 1 2  * 1 2
        {                                                   // 4 5    4 5
            result[i][k] = 0;
            for (int j = 0; j < common; j++)
                result[i][k] += a[i][j] * b[j][k];
        }
    } 
}

void printMatrix(int **matrix, int row, int col)
{
    std::cout << "\n The resultant is Matrix : ";
    for (int i = 0; i < row; i++)
    {
        std::cout << "\n";
        for (int j = 0; j < col; j++)
            std::cout << " " << matrix[i][j];
    } 
}

void fillMatrix(int **a, int row, int col)
{
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            a[i][j] = rand()%10;
}

int main()
{
    int r1, r2, c1, c2;
    std::cout << "\n Enter the size for Matrices(rows and columns respectively) : ";
    std::cout << "\n Matrix 1 : ";
    std::cin >> r1;
    std::cin >> c1; 
    std::cout << "\n Matrix 2 (no. of rows must be equal to no. of columns in matrix 1, So enter columns) : ";
    //sts::cin >> r2;
    std::cin >> c2;
     
    int **res;

    int** a = new int* [r1];
    int** b = new int* [c1];

    

    fillMatrix(a, r1, c1);
    fillMatrix(b, r2, c2);    
    matrixMul(a, b, res, r1, c1, c2);
    printMatrix(res, r1, c2);
    return 0;
}
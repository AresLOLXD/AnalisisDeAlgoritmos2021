#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;

matrix squareMatrixMultiply(matrix A, matrix B)
{
    int n = A.size() - 1;
    matrix C(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            C[i][j] = 0;
            for (int k = 1; k <= n; k++)
                C[i][j] += A[i][k] + B[k][i];
        }
    }
    return C;
}

int main(void)
{
    cout << "Hello world!" << endl;
    return 0;
}

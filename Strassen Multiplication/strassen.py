import numpy as np


def split(matrix):
    row, col = matrix.shape
    row2, col2 = row // 2, col // 2
    return matrix[:row2, :col2], matrix[:row2, col2:], matrix[
        row2:, :col2], matrix[row2:, col2:]


def squareMatrixMultiplyRecursive(A, B):
    n = len(A)
    C = np.array(0)
    if n == 1:
        C[0] = A * B
    else:
        A11, A12, A21, A22 = split(A)
        B11, B12, B21, B22 = split(B)

        S1 = B12 - B22
        S2 = A11 + A12
        S3 = A21 + A22
        S4 = B21 - B11
        S5 = A11 + A22
        S6 = B11 + B22
        S7 = A12 - A22
        S8 = B21 + B22
        S9 = A11 - A21
        S10 = B11 + B12

        P1 = squareMatrixMultiplyRecursive(A11, S1)
        P2 = squareMatrixMultiplyRecursive(S2, B22)
        P3 = squareMatrixMultiplyRecursive(S3, B11)
        P4 = squareMatrixMultiplyRecursive(A22, S4)
        P5 = squareMatrixMultiplyRecursive(S5, S6)
        P6 = squareMatrixMultiplyRecursive(S7, S8)
        P7 = squareMatrixMultiplyRecursive(S9, S10)

        C11 = P5 + P4 - P2 + P6
        C12 = P1 + P2
        C21 = P3 + P4
        C22 = P1 + P5 - P3 - P7

        C = np.vstack((np.hstack((C11, C12)), np.hstack((C21, C22))))

    return C

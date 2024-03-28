#include<stdio.h>
#include<stdlib.h>

void strassen(int n, int A[][n], int B[][n], int C[][n]);

int main() {
    int a[4][4], b[4][4], c[4][4];
    
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    strassen(4, a, b, c);

    printf("Resultant Matrix:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void add(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize], P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Partitioning input matrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculating P values
    subtract(newSize, B12, B22, temp1);
    strassen(newSize, A11, temp1, P1);

    add(newSize, A11, A12, temp1);
    strassen(newSize, temp1, B22, P2);

    add(newSize, A21, A22, temp1);
    strassen(newSize, temp1, B11, P3);

    subtract(newSize, B21, B11, temp1);
    strassen(newSize, A22, temp1, P4);

    add(newSize, A11, A22, temp1);
    add(newSize, B11, B22, temp2);
    strassen(newSize, temp1, temp2, P5);

    subtract(newSize, A12, A22, temp1);
    add(newSize, B21, B22, temp2);
    strassen(newSize, temp1, temp2, P6);

    subtract(newSize, A11, A21, temp1);
    add(newSize, B11, B12, temp2);
    strassen(newSize, temp1, temp2, P7);

    // Calculating C values
    add(newSize, P5, P4, temp1);
    subtract(newSize, temp1, P2, temp2);
    add(newSize, temp2, P6, C11);

    add(newSize, P1, P2, C12);

    add(newSize, P3, P4, C21);

    add(newSize, P5, P1, temp1);
    subtract(newSize, temp1, P3, temp2);
    subtract(newSize, temp2, P7, C22);

    // Combining C matrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

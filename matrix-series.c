/*
Author: Manohar Mukku
Date: 17.07.2018
Desc: GeeksforGeeks - Sudo Placement [1.2] - Matrix Series
Link: https://practice.geeksforgeeks.org/contest-problem/spp-matrix-series/0/
*/

#include <stdio.h>
#include <stdlib.h>

#define mod 1000000007

int** create_matrix(int n) {
    int** matrix = (int**)calloc(n, sizeof(int*));
    int i;
    for (i = 0; i < n; i++)
        matrix[i] = (int*)calloc(n, sizeof(int));

    return matrix;
}

void free_matrix(int** matrix, int n) {
    int i;
    for (i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

int** matmul(int** m1, int** m2, int n) {
    int** result = create_matrix(n);

    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = 0;
            for (k = 0; k < n; k++) {
                result[i][j] = ((long long)(result[i][j]%mod) + (((long long)(m1[i][k] % mod) * (long long)(m2[k][j] % mod)) % mod)) % mod;
            }
        }
    }

    return result;
}

int** matrix_transpose(int** matrix, int n) {
    int** result = create_matrix(n);

    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            result[i][j] = matrix[j][i];

    return result;
}

int** identity_matrix(int n) {
    int** identity = create_matrix(n);

    int i;
    for (i = 0; i < n; i++)
        identity[i][i] = 1;

    return identity;
}

int** matrix_power(int** matrix, int n, long long power) {
    if (power == 0)
        return identity_matrix(n);
    if (power == 1)
        return matrix;

    if (power & 1)
        return matmul(matrix, matrix_power(matrix, n, power-1), n);

    int** aux = matrix_power(matrix, n, power/2);

    return matmul(aux, aux, n);
}

long long fib_m (int n) {
    long long* fib = (long long*)malloc(n * sizeof(long long));

    fib[0] = 1;
    fib[1] = 0;

    int i;
    for (i = 2; i < n; i++)
        fib[i] = fib[i-1] + fib[i-2];

    long long result = fib[n-1];

    free(fib);

    return result;
}

long long fib_mt (int n) {
    long long* fib = (long long*)malloc(n * sizeof(long long));

    fib[0] = 0;
    fib[1] = 1;

    int i;
    for (i = 2; i < n; i++)
        fib[i] = fib[i-1] + fib[i-2];

    long long result = fib[n-1];

    free(fib);

    return result;
}

int main() {
    int T;
    scanf ("%d", &T);

    while (T--) {
        int k, n;
        scanf ("%d %d", &k, &n);

        int i, j;
        int** matrix = create_matrix(k);

        for (i = 0; i < k; i++)
            for (j = 0; j < k; j++)
                scanf ("%d", &matrix[i][j]);


        long long power_m = fib_m(n);
        long long power_mt = fib_mt(n);

        int** aux1 = matrix_power(matrix, k, power_m);
        int** aux2 = matrix_power(matrix_transpose(matrix, k), k, power_mt);

        int** result = matmul(aux1, aux2, k);

        for (i = 0; i < k; i++) {
            for (j = 0; j < k; j++) {
                printf ("%d ", result[i][j]);
            }
            printf("\n");
        }

        free_matrix(matrix, k);
        free_matrix(result, k);
    }
    
    return 0;
}

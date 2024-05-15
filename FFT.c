#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>
#define MAX 100

#define PI 3.141592653589793

// Recursive function to perform FFT
double complex *fft(complex double *X, int N,bool invert) {
    complex double *A=(complex double *)malloc(N * sizeof(complex double));
    if (N == 1) 
    {
        A[0]=X[0];
        return A;
    }
    else
    {
    complex double *even=(complex double *)malloc(N/2 * sizeof(complex double));
    complex double *odd=(complex double *)malloc(N/2 * sizeof(complex double));
    for (int i = 0; i < N/2; i++) {
        even[i] = X[i*2];
        odd[i] = X[i*2+1];
    }
   
    double complex *B=fft(even, N/2,invert);
    double complex *C=fft(odd, N/2,invert);
    free(even);
    free(odd);
    for (int k = 0; k < N/2; k++) {
        complex double t = cexp(-2.0 * I * PI * k / N * (invert ? -1 : 1)) * C[k];

        A[k] = B[k] + t;
        A[k + N/2] = B[k] - t;
        if (invert) {
            A[k] /= 2;
            A[k + N/2] /= 2;
        }
    }
    free(B);
    free(C);
    return A;
    }
}

int main() {
    //double A[] = {6, 7, -10, 9}; // coefficients of first polynomial
    int n,temp;
    printf("enter the size of the array : ");
    scanf("%d",&n);
    double complex A[n];
    printf("Enter the elements of array:");
    for (int i = 0; i < n; ++i) 
    {
        scanf("%d",&temp);
        A[i]=temp;
    }
    double complex * x=fft(A,n,false);
    printf("the elements of transformed array:\n");
    for (int i = 0; i < n; ++i) 
    {
        printf("%.2f + %.2fi\n",creal(x[i]),cimag(x[i]));
    }
    return 0;
}
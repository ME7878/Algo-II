#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>
#define MAX 100

#define PI 3.141592653589793

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

void multiply_polynomials(double *A, double *B, int n1,int n2) {
    int N = 1;
    while (N < (n1+n2-1)) {
        N <<= 1;
    }
    complex double *fa=(complex double *)malloc(N * sizeof(complex double));
    complex double *fb=(complex double *)malloc(N * sizeof(complex double));

    for (int i = 0; i < N; i++) {
        if(i < n1)
            fa[i]=A[i];
        else
            fa[i] =0;
    }
    for (int i = 0; i < N; i++) {
        if(i < n2)
            fb[i]=B[i];
        else
            fb[i] =0;
    }

    double complex *FA=fft(fa, N,false);
    double complex *FB=fft(fb, N,false);

    for (int i = 0; i < N; i++) {
        FA[i] *= FB[i];
    }
    double complex *ifft=fft(FA, N,true);
    printf("Result:\n");
    for (int i = 0; i < n1+n2-1; i++) {
        printf("Coefficient of x^%d:",i);
        printf("%.0f\n", creal(ifft[i])); 
    }
    free(fa);
    free(fb);
    free(FA);
    free(FB);
    free(ifft);
}

int main() {
    int n1;
    double A[MAX];
    printf("enter the size of First polynomial : ");
    scanf("%d",&n1);
    for (int i = 0; i < n1; ++i) 
    {
        printf("Enter coefficient of x^%d:",i);
        scanf("%lf",&A[i]);
    }
    int n2;
    double B[MAX];
    printf("enter the size of second polynomial : ");
    scanf("%d",&n2);
    for (int i = 0; i < n2; ++i) 
    {
        printf("Enter coefficient of x^%d:",i);
        scanf("%lf",&B[i]);
    }

    multiply_polynomials(A, B, n1,n2);

    return 0;
}
// Workshop 3 - Matrix Multiplication - Auto Vectorization
// MatMul.h
// 2018.06.27
// Chris Szalwinski

#include <omp.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>

#pragma once
#define N 512
typedef double array[N];

// matmul returns the product c = a * b
//
void matmul(const double a[][N], const double b[][N], double c[][N], int n) {
    
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// checksum returns the sum of the coefficients in matrix x[N][N]
//
double checksum(const double x[][N]) {
    double sum = 0.0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += x[i][j];
        }
    }
    return sum;
}

// initialize initializes matrix a[N][N]
//
void initialize(double a[][N]) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = static_cast<double>(i * j) / (N * N);
        }
    }
}

void reportTime(const char* msg, std::chrono::steady_clock::duration span) {
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(span);
    std::cout << msg << ": " <<
        ms.count() << " milliseconds" << std::endl;
}

int main(int argc, char** argv) {
    if (argc != 1) {
        std::cerr << "*** Incorrect number of arguments ***\n";
        std::cerr << "Usage: " << argv[0] << "\n";
        return 1;
    }
    std::cout << std::fixed << std::setprecision(2);

    // allocate memory for matrices
    double* a = new double[N*N];
    double* b = new double[N*N];
    double* c = new double[N*N];
    array* aa = (array*)a;
    array* bb = (array*)b;
    array* cc = (array*)c;
    std::cout << "Matrix Multiplication " << N << " by " << N << std::endl;

    // initialize a and b
    std::chrono::steady_clock::time_point ts, te;
    ts = std::chrono::steady_clock::now();
    initialize(aa);
    initialize(bb);
    double* t = c;
    for (int i = 0; i < N * N; i++)
        *t++ = 0.0;
    te = std::chrono::steady_clock::now();
    reportTime("initialization", te - ts);

    // multiply matrices a and b
    ts = std::chrono::steady_clock::now();
    matmul(aa, bb, cc, N);
    te = std::chrono::steady_clock::now();
    reportTime("execution", te - ts);
    std::cout << "checksum = " << checksum(cc) << std::endl;

    // deallocate memory
    delete[] a;
    delete[] b;
    delete[] c;

    std::cout << "max threads: " << omp_get_max_threads() << std::endl;
}


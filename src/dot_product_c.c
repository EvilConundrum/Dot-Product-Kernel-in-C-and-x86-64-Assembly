#include <stdio.h>


double dot_product_c(double *a, double *b, int n){
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}



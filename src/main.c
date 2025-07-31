#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern double dot_product_c(double *vec1, double *vec2, int n);

double get_time_elapsed(clock_t start)
{
    clock_t end = clock();
    return ((double)(end - start)) / (double)CLOCKS_PER_SEC;
}

int main (){
	int n;
	
	// Initialize random seed
	srand(time(NULL));
	
	printf("Enter Vector Length:");
	scanf("%d", &n);
	

	double *vec1 = (double*)malloc(n * sizeof(double));
	double *vec2 = (double*)malloc(n * sizeof(double));
	
	
	// Generate random values for Vector 1
    for (int i = 0; i < n; i++) {
        vec1[i] = ((double)rand() / RAND_MAX) * 200.0 - 100.0; // Random between -100.0 and 100.0

    }
    
	// Generate random values for Vector 2
    for (int i = 0; i < n; i++) {
        vec2[i] = ((double)rand() / RAND_MAX) * 200.0 - 100.0; // Random between -100.0 and 100.0
    }
	
	// Start timing using the proper method
	printf("Starting dot product calculation...\n");
	clock_t start_time = clock();
	
	// Run multiple iterations for measurable timing
	double result_c = 0.0;
	int iterations = 1000000; // 1 million iterations
	
	for (int i = 0; i < iterations; i++) {
		result_c = dot_product_c(vec1, vec2, n);
	}
	
	double execution_time = get_time_elapsed(start_time);
	
	printf("C Result:    %f\n", result_c);
	printf("Iterations performed: %d\n", iterations);
	printf("Total time taken (C implementation): %lf seconds\n", execution_time);
	printf("Average time per calculation: %lf seconds\n", execution_time / iterations);
	printf("Average time per calculation: %.3f microseconds\n", (execution_time / iterations) * 1000000);
	
	// Free allocated memory
	free(vec1);
	free(vec2);

	system("pause");
	
	
return 0;
}



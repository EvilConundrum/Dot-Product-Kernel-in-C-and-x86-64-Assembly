#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern double dot_product_c(double *vec1, double *vec2, int n);
extern void vec_product_asm(double *vec1, double *vec2, double *result, int n);

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
	double result_c = 0.0;
	double result_asm = 0.0;

	
	
	// Generate random values for Vector 1
    for (int i = 0; i < n; i++) {
        vec1[i] = ((double)rand() / RAND_MAX) * 200.0 - 100.0; // Random between -100.0 and 100.0

    }
    
	// Generate random values for Vector 2
    for (int i = 0; i < n; i++) {
        vec2[i] = ((double)rand() / RAND_MAX) * 200.0 - 100.0; // Random between -100.0 and 100.0
    }
	
	// Start timing C implementation
	printf("Starting dot product calculation (C)...\n");
	clock_t start_time_c = clock();
	
	// Perform single dot product calculation (C)
	result_c = dot_product_c(vec1, vec2, n);
	
	clock_t end_time_c = clock();
	double execution_time_c = ((double)(end_time_c - start_time_c)) / CLOCKS_PER_SEC;

	printf("Starting dot product calculation (Assembly)...\n");
	clock_t start_time_asm = clock();

	// Perform single dot product calculation (Assembly)
	vec_product_asm(vec1, vec2, &result_asm, n);

	clock_t end_time_asm = clock();
	double execution_time_asm = ((double)(end_time_asm - start_time_asm)) / CLOCKS_PER_SEC;

	printf("\n=== RESULTS ===\n");
	printf("C Result:        %f\n", result_c);
	printf("Assembly Result: %f\n", result_asm);
	
	printf("\n=== PERFORMANCE ===\n");
	printf("C Time:          %lf seconds (%.3f microseconds)\n", execution_time_c, execution_time_c * 1000000);
	printf("Assembly Time:   %lf seconds (%.3f microseconds)\n", execution_time_asm, execution_time_asm * 1000000);
	
	// Free allocated memory
	free(vec1);
	free(vec2);

	system("pause");
	
	
return 0;
}



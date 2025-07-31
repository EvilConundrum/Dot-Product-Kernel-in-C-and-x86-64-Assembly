# Dot Product Kernel using C and x86-64 Assembly

## Project Overview
This project implements and benchmarks a **dot product kernel** using two approaches:  
1. **C program kernel** (reference version and sanity check).  
2. **x86-64 Assembly kernel** using scalar SIMD floating-point instructions.  

The kernel computes:  

$$
sdot = \sum_{i=1}^{n} A[i] \times B[i]
$$

where:
- `n` is the vector length.
- `A` and `B` are vectors of double-precision floats.
- `sdot` is a scalar double-precision result.  

## Implementation Details

### C Kernel
The C kernel uses a simple loop and standard floating-point multiplication and addition. It acts as the reference implementation.

### x86-64 Assembly Kernel
- Written in MASM syntax.
- Uses **`movsd`**, **`mulsd`**, and **`addsd`** scalar floating-point instructions.

## Example Output  

### C Version (Correctness Check)



### Assembly Version (Correctness Check)



## Performance Comparison  

| Vector Size      | C Kernel (Release) | ASM Kernel (Release) | Speedup |
|-----------------|-------------------|----------------------|---------|
| 2^20 (≈ 1M)     | 00.00 s           | 00.00 s             | 00.00×   |
| 2^24 (≈ 16M)    | 00.00 s           | 00.00 s             | 00.00×   |
| 2^28 (≈ 268M)   | 00.00 s           | 00.00 s              | 00.00×   |

**Observation:** Lorem Ipsum

## Analysis

## How to Build and Run

### Prerequisites


### Build Steps
#### Windows
```bash
# C version


# Assembly version



```
## Screenshots

### C Kernel Output

### Assembly Kernel Output

## Conclusion

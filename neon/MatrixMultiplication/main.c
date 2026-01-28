#include <stdio.h>
#include <arm_neon.h>
#include <time.h>

extern void matrix_multiply_c(float32_t *A, float32_t *B, float32_t *C, uint32_t n, uint32_t m, uint32_t k);
extern void matrix_multiply_4x4_neon(float32_t *A, float32_t *B, float32_t *C);

int main(int argc, char *argv[])
{
    const uint32_t n = 4;
    const uint32_t m = 4;
    const uint32_t k = 4;

    float32_t m1[n * k];
    float32_t m2[k * m];
    float32_t m_result[n * m];

    for (size_t i = 0; i < sizeof(m1) / sizeof(m1[0]); i++)
    {
        m1[i] = i + 0.0f;
    }

    for (size_t i = 0; i < sizeof(m2) / sizeof(m2[0]); i++)
    {
        m2[i] = i + 0.0f;
    }

    clock_t start = clock();
    matrix_multiply_c(m1, m2, m_result, n, m, k);
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("函数执行时间 C：%.6f 秒\n", elapsed_time);

    start = clock();
    matrix_multiply_4x4_neon(m1, m2, m_result);
    end = clock();
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("函数执行时间 neon：%.6f 秒\n", elapsed_time);
    return 0;
}
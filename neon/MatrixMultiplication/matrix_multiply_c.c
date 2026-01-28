#include <stdint.h>
#include <arm_neon.h>

// 矩阵乘法：C = A × B
// A: 输入矩阵，维度 n×k（行优先存储）
// B: 输入矩阵，维度 k×m（行优先存储）
// C: 输出矩阵，维度 n×m（行优先存储）
// n: A 的行数 / C 的行数
// m: B 的列数 / C 的列数
// k: A 的列数 / B 的行数
void matrix_multiply_c(float32_t *A, float32_t *B, float32_t *C, uint32_t n, uint32_t m, uint32_t k)
{
    for (int i_idx = 0; i_idx < n; i_idx++)
    {
        for (int j_idx = 0; j_idx < m; j_idx++)
        {
            uint32_t c_offset = n * j_idx;
            C[c_offset + i_idx] = 0;
            for (int k_idx = 0; k_idx < k; k_idx++)
            {
                C[c_offset + i_idx] += A[n * k_idx + i_idx] * B[k * j_idx + k_idx];
            }
        }
    }
}
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

extern void rgb_deinterleave_c(uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *rgb, int len_color);
extern void rgb_deinterleave_neon(uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *rgb, int len_color);

static uint8_t *alloc_rgb(uint32_t pixels)
{
    uint8_t *rgb = malloc(pixels * 3);

    for (size_t i = 0; i < pixels; i++)
    {
        size_t idx = i * 3;
        rgb[idx] = 0x1;
        rgb[idx + 1] = 0x2;
        rgb[idx + 2] = 0x3;
    }
    return rgb;
}

static void delete_rgb(uint8_t **rgb)
{
    if (rgb != NULL && *rgb != NULL)
    {
        free(*rgb);
        *rgb = NULL;
    }
}

int main(int argc, char *argv[])
{
    const uint32_t pixels = 10000;
    uint8_t *rgb = alloc_rgb(pixels);
    uint8_t r[pixels], g[pixels], b[pixels];
    
    clock_t start = clock();
    rgb_deinterleave_c(r, g, b, rgb, pixels);
    clock_t end = clock();
    double elapsed_time_c = (double)(end - start) / CLOCKS_PER_SEC;

    memset(r, 0x00, sizeof(r));
    memset(g, 0x00, sizeof(g));
    memset(b, 0x00, sizeof(b));

    start = clock();
    rgb_deinterleave_neon(r, g, b, rgb, pixels);
    end = clock();
    double elapsed_time_neon = (double)(end - start) / CLOCKS_PER_SEC;
    printf("C语言 执行时间：%.4f 秒\n", elapsed_time_c);
    printf("NEON 执行时间：%.4f 秒\n", elapsed_time_neon);
    delete_rgb(&rgb); return 0;
}
#include <stdint.h>
#include <stddef.h>

void rgb_deinterleave_c(uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *rgb, int len_color)
{
    for (int i = 0; i < len_color; i++)
    {
        size_t idx = i * 3;
        r[i] = rgb[idx];
        g[i] = rgb[idx + 1];
        b[i] = rgb[idx + 2];
    }
}

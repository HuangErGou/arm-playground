#include <stdint.h>
#include <stddef.h>
#include <arm_neon.h>

void rgb_deinterleave_neon(uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *rgb, int len_color)
{
    /*
     * Take the elements of "rgb" and store the individual colors "r", "g", and "b"
     */
    int num8x16 = len_color / 16;
    uint8x16x3_t intlv_rgb;
    for (int i = 0; i < num8x16; i++)
    {
        size_t idx = i * 16;
        intlv_rgb = vld3q_u8(rgb + idx * 3);
        vst1q_u8(r + idx, intlv_rgb.val[0]);
        vst1q_u8(g + idx, intlv_rgb.val[1]);
        vst1q_u8(b + idx, intlv_rgb.val[2]);
    }

    int remainder = len_color % 16;
    int processed_pixels = len_color - remainder;
    rgb = rgb + processed_pixels * 3;
    r += processed_pixels;
    g += processed_pixels;
    b += processed_pixels;
    for (int i = 0; i < remainder; i++) {
        r[i] = rgb[i];
        g[i] = rgb[i + 1];
        b[i] = rgb[i + 2];
    }
}
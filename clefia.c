#include <stdio.h>
#include <stdlib.h>

#define M0_4   0xf0000000
#define M4_8   0x0f000000
#define M8_12  0x00f00000
#define M12_16 0x000f0000
#define M16_20 0x0000f000
#define M20_24 0x00000f00
#define M24_28 0x000000f0
#define M28_32 0x0000000f

#define M0_8     0xff000000
#define M8_16    0x00ff0000
#define M16_24   0x0000ff00
#define M24_32   0x000000ff


unsigned int f0(unsigned int rk, unsigned int x) {
  unsigned int t = rk ^ x;
  char t0 = t & M0_8;
  char t1 = t & M8_16;
  char t2 = t & M16_24;
  char t3 = t & M24_32;
}

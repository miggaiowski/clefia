#include <stdio.h>
#include <stdlib.h>

#define ROUNDS128 18

#define W0_4   0xf0000000
#define W4_8   0x0f000000
#define W8_12  0x00f00000
#define W12_16 0x000f0000
#define W16_20 0x0000f000
#define W20_24 0x00000f00
#define W24_28 0x000000f0
#define W28_32 0x0000000f
#define W0_8   0xff000000
#define W8_16  0x00ff0000
#define W16_24 0x0000ff00
#define W24_32 0x000000ff

#define B0_4   0xf0
#define B4_8   0x0f

unsigned int f0(unsigned int rk, unsigned int x) {
  /* Step 1 */
  unsigned int t = rk ^ x;
  /* Step 2 */
  char t0 = t & W0_8;
  char t1 = t & W8_16;
  char t2 = t & W16_24;
  char t3 = t & W24_32;
  t0 = s0[t0 & B0_4][t0 & B4_8];
  t1 = s1[t1 & B0_4][t1 & B4_8];
  t2 = s0[t2 & B0_4][t2 & B4_8];
  t3 = s1[t3 & B0_4][t3 & B4_8];
  /* Step 3 */
  
}

unsigned int f1(unsigned int rk, unsigned int x) {
  /* Step 1 */
  unsigned int t = rk ^ x;
  /* Step 2 */
  char t0 = t & W0_8;
  char t1 = t & W8_16;
  char t2 = t & W16_24;
  char t3 = t & W24_32;
  t0 = s1[t0 & B0_4][t0 & B4_8];
  t1 = s0[t1 & B0_4][t1 & B4_8];
  t2 = s1[t2 & B0_4][t2 & B4_8];
  t3 = s0[t3 & B0_4][t3 & B4_8];
  /* Step 3 */
  
}

void encryption(unsigned int p*, unsigned int c*) {

	unsigned int t* = malloc(sizeof(unsigned int) * 4);
	unsigned int wk* = malloc(sizeof(unsigned int) * 4);
	unsigned int rk* = malloc(sizeof(unsigned int) * 36);
	
	int r;
	for (r = 1; r <= ROUNDS128; r++) {
	
		key_scheduling(r, wk, rk);
		
		/* step 1 */
		t[0] = p[0];
		t[1] = p[1] ^ wk[0];
		t[2] = p[2];
		t[3] = p[3] ^ wk[1];
		
		/* step 2 */
		GFN(4, r, rk, t, y);
		t[0] = y[0];
		t[1] = y[1];
		t[2] = y[2];
		t[3] = y[3];
		
		/* step 3 */
		
	}
}


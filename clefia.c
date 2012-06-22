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

char s0[16][16] = {
  0x57, 0x49, 0xd1, 0xc6, 0x2f, 0x33, 0x74, 0xfb, 0x95, 0x6d, 0x82, 0xea, 0x0e, 0xb0, 0xa8, 0x1c,
  0x28, 0xd0, 0x4b, 0x92, 0x5c, 0xee, 0x85, 0xb1, 0xc4, 0x0a, 0x76, 0x3d, 0x63, 0xf9, 0x17, 0xaf,
  0xbf, 0xa1, 0x19, 0x65, 0xf7, 0x7a, 0x32, 0x20, 0x06, 0xce, 0xe4, 0x83, 0x9d, 0x5b, 0x4c, 0xd8,
  0x42, 0x5d, 0x2e, 0xe8, 0xd4, 0x9b, 0x0f, 0x13, 0x3c, 0x89, 0x67, 0xc0, 0x71, 0xaa, 0xb6, 0xf5,
  0xa4, 0xbe, 0xfd, 0x8c, 0x12, 0x00, 0x97, 0xda, 0x78, 0xe1, 0xcf, 0x6b, 0x39, 0x43, 0x55, 0x26,
  0x30, 0x98, 0xcc, 0xdd, 0xeb, 0x54, 0xb3, 0x8f, 0x4e, 0x16, 0xfa, 0x22, 0xa5, 0x77, 0x09, 0x61,
  0xd6, 0x2a, 0x53, 0x37, 0x45, 0xc1, 0x6c, 0xae, 0xef, 0x70, 0x08, 0x99, 0x8b, 0x1d, 0xf2, 0xb4,
  0xe9, 0xc7, 0x9f, 0x4a, 0x31, 0x25, 0xfe, 0x7c, 0xd3, 0xa2, 0xbd, 0x56, 0x14, 0x88, 0x60, 0x0b,
  0xcd, 0xe2, 0x34, 0x50, 0x9e, 0xdc, 0x11, 0x05, 0x2b, 0xb7, 0xa9, 0x48, 0xff, 0x66, 0x8a, 0x73,
  0x03, 0x75, 0x86, 0xf1, 0x6a, 0xa7, 0x40, 0xc2, 0xb9, 0x2c, 0xdb, 0x1f, 0x58, 0x94, 0x3e, 0xed,
  0xfc, 0x1b, 0xa0, 0x04, 0xb8, 0x8d, 0xe6, 0x59, 0x62, 0x93, 0x35, 0x7e, 0xca, 0x21, 0xdf, 0x47,
  0x15, 0xf3, 0xba, 0x7f, 0xa6, 0x69, 0xc8, 0x4d, 0x87, 0x3b, 0x9c, 0x01, 0xe0, 0xde, 0x24, 0x52,
  0x7b, 0x0c, 0x68, 0x1e, 0x80, 0xb2, 0x5a, 0xe7, 0xad, 0xd5, 0x23, 0xf4, 0x46, 0x3f, 0x91, 0xc9,
  0x6e, 0x84, 0x72, 0xbb, 0x0d, 0x18, 0xd9, 0x96, 0xf0, 0x5f, 0x41, 0xac, 0x27, 0xc5, 0xe3, 0x3a,
  0x81, 0x6f, 0x07, 0xa3, 0x79, 0xf6, 0x2d, 0x38, 0x1a, 0x44, 0x5e, 0xb5, 0xd2, 0xec, 0xcb, 0x90,
  0x9a, 0x36, 0xe5, 0x29, 0xc3, 0x4f, 0xab, 0x64, 0x51, 0xf8, 0x10, 0xd7, 0xbc, 0x02, 0x7d, 0x8e};

char s1[16][16] = {
  0x6c, 0xda, 0xc3, 0xe9, 0x4e, 0x9d, 0x0a, 0x3d, 0xb8, 0x36, 0xb4, 0x38, 0x13, 0x34, 0x0c, 0xd9,
  0xbf, 0x74, 0x94, 0x8f, 0xb7, 0x9c, 0xe5, 0xdc, 0x9e, 0x07, 0x49, 0x4f, 0x98, 0x2c, 0xb0, 0x93,
  0x12, 0xeb, 0xcd, 0xb3, 0x92, 0xe7, 0x41, 0x60, 0xe3, 0x21, 0x27, 0x3b, 0xe6, 0x19, 0xd2, 0x0e,
  0x91, 0x11, 0xc7, 0x3f, 0x2a, 0x8e, 0xa1, 0xbc, 0x2b, 0xc8, 0xc5, 0x0f, 0x5b, 0xf3, 0x87, 0x8b,
  0xfb, 0xf5, 0xde, 0x20, 0xc6, 0xa7, 0x84, 0xce, 0xd8, 0x65, 0x51, 0xc9, 0xa4, 0xef, 0x43, 0x53,
  0x25, 0x5d, 0x9b, 0x31, 0xe8, 0x3e, 0x0d, 0xd7, 0x80, 0xff, 0x69, 0x8a, 0xba, 0x0b, 0x73, 0x5c,
  0x6e, 0x54, 0x15, 0x62, 0xf6, 0x35, 0x30, 0x52, 0xa3, 0x16, 0xd3, 0x28, 0x32, 0xfa, 0xaa, 0x5e,
  0xcf, 0xea, 0xed, 0x78, 0x33, 0x58, 0x09, 0x7b, 0x63, 0xc0, 0xc1, 0x46, 0x1e, 0xdf, 0xa9, 0x99,
  0x55, 0x04, 0xc4, 0x86, 0x39, 0x77, 0x82, 0xec, 0x40, 0x18, 0x90, 0x97, 0x59, 0xdd, 0x83, 0x1f,
  0x9a, 0x37, 0x06, 0x24, 0x64, 0x7c, 0xa5, 0x56, 0x48, 0x08, 0x85, 0xd0, 0x61, 0x26, 0xca, 0x6f,
  0x7e, 0x6a, 0xb6, 0x71, 0xa0, 0x70, 0x05, 0xd1, 0x45, 0x8c, 0x23, 0x1c, 0xf0, 0xee, 0x89, 0xad,
  0x7a, 0x4b, 0xc2, 0x2f, 0xdb, 0x5a, 0x4d, 0x76, 0x67, 0x17, 0x2d, 0xf4, 0xcb, 0xb1, 0x4a, 0xa8,
  0xb5, 0x22, 0x47, 0x3a, 0xd5, 0x10, 0x4c, 0x72, 0xcc, 0x00, 0xf9, 0xe0, 0xfd, 0xe2, 0xfe, 0xae,
  0xf8, 0x5f, 0xab, 0xf1, 0x1b, 0x42, 0x81, 0xd6, 0xbe, 0x44, 0x29, 0xa6, 0x57, 0xb9, 0xaf, 0xf2,
  0xd4, 0x75, 0x66, 0xbb, 0x68, 0x9f, 0x50, 0x02, 0x01, 0x3c, 0x7f, 0x8d, 0x1a, 0x88, 0xbd, 0xac,
  0xf7, 0xe4, 0x79, 0x96, 0xa2, 0xfc, 0x6d, 0xb2, 0x6b, 0x03, 0xe1, 0x2e, 0x7d, 0x14, 0x95, 0x1d};

unsigned int word_from_bytes(char a, char b, char c, char d) {
  unsigned int res = 0;
  res = (a << 24) + (b << 16) + (c << 8) + d;
  return res;
}

unsigned char mul2(unsigned char x) {
  /* multiplicacao em GF(2^8) (p(x) = '11d') */
  if(x & 0x80U){
    x ^= 0x0eU;
  }
  return ((x << 1) | (x >> 7));
}

#define mul4(_x) (mul2(mul2((_x))))
#define mul6(_x) (mul2((_x)) ^ mul4((_x)))
#define mul8(_x) (mul2(mul4((_x))))
#define mulA(_x) (mul2((_x)) ^ mul8((_x)))

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
  char y0 =      t0  ^ mul2(t1) ^ mul4(t2) ^ mul6(t3);
  char y1 = mul2(t0) ^      t1  ^ mul6(t2) ^ mul4(t3);
  char y2 = mul4(t0) ^ mul6(t1) ^      t2  ^ mul2(t3);
  char y3 = mul6(t0) ^ mul4(t1) ^ mul2(t2) ^       t3;
  return word_from_bytes(y0, y1, y2, y3);
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
  char y0 =      t0  ^ mul8(t1) ^ mul2(t2) ^ mulA(t3);
  char y1 = mul8(t0) ^      t1  ^ mulA(t2) ^ mul2(t3);
  char y2 = mul2(t0) ^ mulA(t1) ^      t2  ^ mul8(t3);
  char y3 = mulA(t0) ^ mul2(t1) ^ mul8(t2) ^       t3;
  return word_from_bytes(y0, y1, y2, y3);
}

void gfn4(int r, unsigned int* rk, unsigned int *x, unsigned int *y) {
  int i;
  unsigned int temp;
  /* Step 1 */
  unsigned int t0 = x[0];
  unsigned int t1 = x[1];
  unsigned int t2 = x[2];
  unsigned int t3 = x[3];
  /* Step 2 */
  for (i = 0; i < r; i++) {
    /* Step 2.1 */
    t1 ^= f0(rk[2*i], t0);
    t3 ^= f1(rk[2*i + 1], t2);    
    /* Step 2.2 */
    temp = t0;
    t0 = t1;
    t1 = t2;
    t2 = t3;
    t3 = temp;
  }
  /* Step 3 */
  y[0] = t3;
  y[1] = t0;
  y[2] = t1;
  y[3] = t2;
}

void gfn8(int r, unsigned int* rk, unsigned int *x, unsigned int *y) {
  int i;
  unsigned int temp;
  /* Step 1 */
  unsigned int t0 = x[0];
  unsigned int t1 = x[1];
  unsigned int t2 = x[2];
  unsigned int t3 = x[3];
  unsigned int t4 = x[4];
  unsigned int t5 = x[5];
  unsigned int t6 = x[6];
  unsigned int t7 = x[7];
  /* Step 2 */
  for (i = 0; i < r; i++) {
    /* Step 2.1 */
    t1 ^= f0(rk[4*i], t0);
    t3 ^= f1(rk[4*i + 1], t2);    
    t5 ^= f0(rk[4*1 + 2], t4);
    t7 ^= f1(rk[4*i + 3], t6);
    /* Step 2.2 */
    temp = t0;
    t0 = t1;
    t1 = t2;
    t2 = t3;
    t3 = t4;
    t4 = t5;
    t5 = t6;
    t6 = t7;
    t7 = temp;
  }
  /* Step 3 */
  y[0] = t7;
  y[1] = t0;
  y[2] = t1;
  y[3] = t2;
  y[4] = t3;
  y[5] = t4;
  y[6] = t5;
  y[7] = t6;
}

void gfn_inv4(int r, unsigned int* rk, unsigned int *x, unsigned int *y) {
  int i;
  unsigned int temp0;
  unsigned int temp1;
  unsigned int temp2;
  unsigned int temp3;
  /* Step 1 */
  unsigned int t0 = x[0];
  unsigned int t1 = x[1];
  unsigned int t2 = x[2];
  unsigned int t3 = x[3];
  /* Step 2 */
  for (i = 0; i < r; i++) {
    /* Step 2.1 */
    t1 ^= f0(rk[2*(r-i) - 2], t0);
    t3 ^= f1(rk[2*(r-i) - 1], t2);    
    /* Step 2.2 */
    temp0 = t0;
    temp1 = t1;
    temp2 = t2;
    temp3 = t3;
    t0 = temp3;
    t1 = temp0;
    t2 = temp1;
    t3 = temp2;
  }
  /* Step 3 */
  y[0] = t1;
  y[1] = t2;
  y[2] = t3;
  y[3] = t0;
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
		c[0] = t[0];
		c[1] = t[1] ^ wk[2];
		c[2] = t[2];
		c[3] = t[3] ^ wk[3];
	}
}

void decryption(unsigned int p*, unsigned int c*) {
	
	unsigned int t* = malloc(sizeof(unsigned int) * 4);
	unsigned int wk* = malloc(sizeof(unsigned int) * 4);
	unsigned int rk* = malloc(sizeof(unsigned int) * 36);
	
	int r;
	for (r = 1; r <= ROUNDS128; r++) {
		
		key_scheduling(r, wk, rk);
		
		/* step 1 */
		t[0] = c[0];
		t[1] = c[1] ^ wk[2];
		t[2] = c[2];
		t[3] = c[3] ^ wk[3];
		
		/* step 2 */
		GFNINV(4, r, rk, t, y);
		t[0] = y[0];
		t[1] = y[1];
		t[2] = y[2];
		t[3] = y[3];
		
		/* step 3 */
		p[0] = t[0];
		p[1] = t[1] ^ wk[0];
		p[2] = t[2];
		p[3] = t[3] ^ wk[1];	
	}	
}


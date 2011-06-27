#ifdef __i386
//#include <stdio.h>
#include "mad.h.x86"
#define printf(args...)
#else
#include "mad.h.mips"
#define printf(args...)
#endif

void *memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned char *dest_b, *src_b;

	dest_b = (unsigned char*)dest;
	src_b  = (unsigned char*)src;

	while(n--) {
		dest_b[n] = src_b[n];
	}
	return dest;
}


static inline
void imdct36(mad_fixed_t const X[18], mad_fixed_t x[36])
{
  mad_fixed_t t0, t1, t2,  t3,  t4,  t5,  t6,  t7;
  mad_fixed_t t8, t9, t10, t11, t12, t13, t14, t15;
  register mad_fixed64hi_t hi;
  register mad_fixed64lo_t lo;

  MAD_F_ML0(hi, lo, X[4],  MAD_F(0x0ec835e8));
  MAD_F_MLA(hi, lo, X[13], MAD_F(0x061f78aa));

  t6 = MAD_F_MLZ(hi, lo);

  MAD_F_MLA(hi, lo, (t14 = X[1] - X[10]), -MAD_F(0x061f78aa));
  MAD_F_MLA(hi, lo, (t15 = X[7] + X[16]), -MAD_F(0x0ec835e8));

  t0 = MAD_F_MLZ(hi, lo);

  MAD_F_MLA(hi, lo, (t8  = X[0] - X[11] - X[12]),  MAD_F(0x0216a2a2));
  MAD_F_MLA(hi, lo, (t9  = X[2] - X[9]  - X[14]),  MAD_F(0x09bd7ca0));
  MAD_F_MLA(hi, lo, (t10 = X[3] - X[8]  - X[15]), -MAD_F(0x0cb19346));
  MAD_F_MLA(hi, lo, (t11 = X[5] - X[6]  - X[17]), -MAD_F(0x0fdcf549));

  x[7]  = MAD_F_MLZ(hi, lo);
  x[10] = -x[7];

  MAD_F_ML0(hi, lo, t8,  -MAD_F(0x0cb19346));
  MAD_F_MLA(hi, lo, t9,   MAD_F(0x0fdcf549));
  MAD_F_MLA(hi, lo, t10,  MAD_F(0x0216a2a2));
  MAD_F_MLA(hi, lo, t11, -MAD_F(0x09bd7ca0));

  x[19] = x[34] = MAD_F_MLZ(hi, lo) - t0;

  t12 = X[0] - X[3] + X[8] - X[11] - X[12] + X[15];
  t13 = X[2] + X[5] - X[6] - X[9]  - X[14] - X[17];

  MAD_F_ML0(hi, lo, t12, -MAD_F(0x0ec835e8));
  MAD_F_MLA(hi, lo, t13,  MAD_F(0x061f78aa));

  x[22] = x[31] = MAD_F_MLZ(hi, lo) + t0;

  MAD_F_ML0(hi, lo, X[1],  -MAD_F(0x09bd7ca0));
  MAD_F_MLA(hi, lo, X[7],   MAD_F(0x0216a2a2));
  MAD_F_MLA(hi, lo, X[10], -MAD_F(0x0fdcf549));
  MAD_F_MLA(hi, lo, X[16],  MAD_F(0x0cb19346));

  t1 = MAD_F_MLZ(hi, lo) + t6;

  MAD_F_ML0(hi, lo, X[0],   MAD_F(0x03768962));
  MAD_F_MLA(hi, lo, X[2],   MAD_F(0x0e313245));
  MAD_F_MLA(hi, lo, X[3],  -MAD_F(0x0ffc19fd));
  MAD_F_MLA(hi, lo, X[5],  -MAD_F(0x0acf37ad));
  MAD_F_MLA(hi, lo, X[6],   MAD_F(0x04cfb0e2));
  MAD_F_MLA(hi, lo, X[8],  -MAD_F(0x0898c779));
  MAD_F_MLA(hi, lo, X[9],   MAD_F(0x0d7e8807));
  MAD_F_MLA(hi, lo, X[11],  MAD_F(0x0f426cb5));
  MAD_F_MLA(hi, lo, X[12], -MAD_F(0x0bcbe352));
  MAD_F_MLA(hi, lo, X[14],  MAD_F(0x00b2aa3e));
  MAD_F_MLA(hi, lo, X[15], -MAD_F(0x07635284));
  MAD_F_MLA(hi, lo, X[17], -MAD_F(0x0f9ee890));

  x[6]  = MAD_F_MLZ(hi, lo) + t1;
  x[11] = -x[6];

  MAD_F_ML0(hi, lo, X[0],  -MAD_F(0x0f426cb5));
  MAD_F_MLA(hi, lo, X[2],  -MAD_F(0x00b2aa3e));
  MAD_F_MLA(hi, lo, X[3],   MAD_F(0x0898c779));
  MAD_F_MLA(hi, lo, X[5],   MAD_F(0x0f9ee890));
  MAD_F_MLA(hi, lo, X[6],   MAD_F(0x0acf37ad));
  MAD_F_MLA(hi, lo, X[8],  -MAD_F(0x07635284));
  MAD_F_MLA(hi, lo, X[9],  -MAD_F(0x0e313245));
  MAD_F_MLA(hi, lo, X[11], -MAD_F(0x0bcbe352));
  MAD_F_MLA(hi, lo, X[12], -MAD_F(0x03768962));
  MAD_F_MLA(hi, lo, X[14],  MAD_F(0x0d7e8807));
  MAD_F_MLA(hi, lo, X[15],  MAD_F(0x0ffc19fd));
  MAD_F_MLA(hi, lo, X[17],  MAD_F(0x04cfb0e2));

  x[23] = x[30] = MAD_F_MLZ(hi, lo) + t1;

  MAD_F_ML0(hi, lo, X[0],  -MAD_F(0x0bcbe352));
  MAD_F_MLA(hi, lo, X[2],   MAD_F(0x0d7e8807));
  MAD_F_MLA(hi, lo, X[3],  -MAD_F(0x07635284));
  MAD_F_MLA(hi, lo, X[5],   MAD_F(0x04cfb0e2));
  MAD_F_MLA(hi, lo, X[6],   MAD_F(0x0f9ee890));
  MAD_F_MLA(hi, lo, X[8],  -MAD_F(0x0ffc19fd));
  MAD_F_MLA(hi, lo, X[9],  -MAD_F(0x00b2aa3e));
  MAD_F_MLA(hi, lo, X[11],  MAD_F(0x03768962));
  MAD_F_MLA(hi, lo, X[12], -MAD_F(0x0f426cb5));
  MAD_F_MLA(hi, lo, X[14],  MAD_F(0x0e313245));
  MAD_F_MLA(hi, lo, X[15],  MAD_F(0x0898c779));
  MAD_F_MLA(hi, lo, X[17], -MAD_F(0x0acf37ad));

  x[18] = x[35] = MAD_F_MLZ(hi, lo) - t1;

  MAD_F_ML0(hi, lo, X[4],   MAD_F(0x061f78aa));
  MAD_F_MLA(hi, lo, X[13], -MAD_F(0x0ec835e8));

  t7 = MAD_F_MLZ(hi, lo);

  MAD_F_MLA(hi, lo, X[1],  -MAD_F(0x0cb19346));
  MAD_F_MLA(hi, lo, X[7],   MAD_F(0x0fdcf549));
  MAD_F_MLA(hi, lo, X[10],  MAD_F(0x0216a2a2));
  MAD_F_MLA(hi, lo, X[16], -MAD_F(0x09bd7ca0));

  t2 = MAD_F_MLZ(hi, lo);

  MAD_F_MLA(hi, lo, X[0],   MAD_F(0x04cfb0e2));
  MAD_F_MLA(hi, lo, X[2],   MAD_F(0x0ffc19fd));
  MAD_F_MLA(hi, lo, X[3],  -MAD_F(0x0d7e8807));
  MAD_F_MLA(hi, lo, X[5],   MAD_F(0x03768962));
  MAD_F_MLA(hi, lo, X[6],  -MAD_F(0x0bcbe352));
  MAD_F_MLA(hi, lo, X[8],  -MAD_F(0x0e313245));
  MAD_F_MLA(hi, lo, X[9],   MAD_F(0x07635284));
  MAD_F_MLA(hi, lo, X[11], -MAD_F(0x0acf37ad));
  MAD_F_MLA(hi, lo, X[12],  MAD_F(0x0f9ee890));
  MAD_F_MLA(hi, lo, X[14],  MAD_F(0x0898c779));
  MAD_F_MLA(hi, lo, X[15],  MAD_F(0x00b2aa3e));
  MAD_F_MLA(hi, lo, X[17],  MAD_F(0x0f426cb5));

  x[5]  = MAD_F_MLZ(hi, lo);
  x[12] = -x[5];

  MAD_F_ML0(hi, lo, X[0],   MAD_F(0x0acf37ad));
  MAD_F_MLA(hi, lo, X[2],  -MAD_F(0x0898c779));
  MAD_F_MLA(hi, lo, X[3],   MAD_F(0x0e313245));
  MAD_F_MLA(hi, lo, X[5],  -MAD_F(0x0f426cb5));
  MAD_F_MLA(hi, lo, X[6],  -MAD_F(0x03768962));
  MAD_F_MLA(hi, lo, X[8],   MAD_F(0x00b2aa3e));
  MAD_F_MLA(hi, lo, X[9],  -MAD_F(0x0ffc19fd));
  MAD_F_MLA(hi, lo, X[11],  MAD_F(0x0f9ee890));
  MAD_F_MLA(hi, lo, X[12], -MAD_F(0x04cfb0e2));
  MAD_F_MLA(hi, lo, X[14],  MAD_F(0x07635284));
  MAD_F_MLA(hi, lo, X[15],  MAD_F(0x0d7e8807));
  MAD_F_MLA(hi, lo, X[17], -MAD_F(0x0bcbe352));

  x[0]  = MAD_F_MLZ(hi, lo) + t2;
  x[17] = -x[0];

  MAD_F_ML0(hi, lo, X[0],  -MAD_F(0x0f9ee890));
  MAD_F_MLA(hi, lo, X[2],  -MAD_F(0x07635284));
  MAD_F_MLA(hi, lo, X[3],  -MAD_F(0x00b2aa3e));
  MAD_F_MLA(hi, lo, X[5],   MAD_F(0x0bcbe352));
  MAD_F_MLA(hi, lo, X[6],   MAD_F(0x0f426cb5));
  MAD_F_MLA(hi, lo, X[8],   MAD_F(0x0d7e8807));
  MAD_F_MLA(hi, lo, X[9],   MAD_F(0x0898c779));
  MAD_F_MLA(hi, lo, X[11], -MAD_F(0x04cfb0e2));
  MAD_F_MLA(hi, lo, X[12], -MAD_F(0x0acf37ad));
  MAD_F_MLA(hi, lo, X[14], -MAD_F(0x0ffc19fd));
  MAD_F_MLA(hi, lo, X[15], -MAD_F(0x0e313245));
  MAD_F_MLA(hi, lo, X[17], -MAD_F(0x03768962));

  x[24] = x[29] = MAD_F_MLZ(hi, lo) + t2;

  MAD_F_ML0(hi, lo, X[1],  -MAD_F(0x0216a2a2));
  MAD_F_MLA(hi, lo, X[7],  -MAD_F(0x09bd7ca0));
  MAD_F_MLA(hi, lo, X[10],  MAD_F(0x0cb19346));
  MAD_F_MLA(hi, lo, X[16],  MAD_F(0x0fdcf549));

  t3 = MAD_F_MLZ(hi, lo) + t7;

  MAD_F_ML0(hi, lo, X[0],   MAD_F(0x00b2aa3e));
  MAD_F_MLA(hi, lo, X[2],   MAD_F(0x03768962));
  MAD_F_MLA(hi, lo, X[3],  -MAD_F(0x04cfb0e2));
  MAD_F_MLA(hi, lo, X[5],  -MAD_F(0x07635284));
  MAD_F_MLA(hi, lo, X[6],   MAD_F(0x0898c779));
  MAD_F_MLA(hi, lo, X[8],   MAD_F(0x0acf37ad));
  MAD_F_MLA(hi, lo, X[9],  -MAD_F(0x0bcbe352));
  MAD_F_MLA(hi, lo, X[11], -MAD_F(0x0d7e8807));
  MAD_F_MLA(hi, lo, X[12],  MAD_F(0x0e313245));
  MAD_F_MLA(hi, lo, X[14],  MAD_F(0x0f426cb5));
  MAD_F_MLA(hi, lo, X[15], -MAD_F(0x0f9ee890));
  MAD_F_MLA(hi, lo, X[17], -MAD_F(0x0ffc19fd));

  x[8] = MAD_F_MLZ(hi, lo) + t3;
  x[9] = -x[8];

  MAD_F_ML0(hi, lo, X[0],  -MAD_F(0x0e313245));
  MAD_F_MLA(hi, lo, X[2],   MAD_F(0x0bcbe352));
  MAD_F_MLA(hi, lo, X[3],   MAD_F(0x0f9ee890));
  MAD_F_MLA(hi, lo, X[5],  -MAD_F(0x0898c779));
  MAD_F_MLA(hi, lo, X[6],  -MAD_F(0x0ffc19fd));
  MAD_F_MLA(hi, lo, X[8],   MAD_F(0x04cfb0e2));
  MAD_F_MLA(hi, lo, X[9],   MAD_F(0x0f426cb5));
  MAD_F_MLA(hi, lo, X[11], -MAD_F(0x00b2aa3e));
  MAD_F_MLA(hi, lo, X[12], -MAD_F(0x0d7e8807));
  MAD_F_MLA(hi, lo, X[14], -MAD_F(0x03768962));
  MAD_F_MLA(hi, lo, X[15],  MAD_F(0x0acf37ad));
  MAD_F_MLA(hi, lo, X[17],  MAD_F(0x07635284));

  x[21] = x[32] = MAD_F_MLZ(hi, lo) + t3;

  MAD_F_ML0(hi, lo, X[0],  -MAD_F(0x0d7e8807));
  MAD_F_MLA(hi, lo, X[2],   MAD_F(0x0f426cb5));
  MAD_F_MLA(hi, lo, X[3],   MAD_F(0x0acf37ad));
  MAD_F_MLA(hi, lo, X[5],  -MAD_F(0x0ffc19fd));
  MAD_F_MLA(hi, lo, X[6],  -MAD_F(0x07635284));
  MAD_F_MLA(hi, lo, X[8],   MAD_F(0x0f9ee890));
  MAD_F_MLA(hi, lo, X[9],   MAD_F(0x03768962));
  MAD_F_MLA(hi, lo, X[11], -MAD_F(0x0e313245));
  MAD_F_MLA(hi, lo, X[12],  MAD_F(0x00b2aa3e));
  MAD_F_MLA(hi, lo, X[14],  MAD_F(0x0bcbe352));
  MAD_F_MLA(hi, lo, X[15], -MAD_F(0x04cfb0e2));
  MAD_F_MLA(hi, lo, X[17], -MAD_F(0x0898c779));

  x[20] = x[33] = MAD_F_MLZ(hi, lo) - t3;

  MAD_F_ML0(hi, lo, t14, -MAD_F(0x0ec835e8));
  MAD_F_MLA(hi, lo, t15,  MAD_F(0x061f78aa));

  t4 = MAD_F_MLZ(hi, lo) - t7;

  MAD_F_ML0(hi, lo, t12, MAD_F(0x061f78aa));
  MAD_F_MLA(hi, lo, t13, MAD_F(0x0ec835e8));

  x[4]  = MAD_F_MLZ(hi, lo) + t4;
  x[13] = -x[4];

  MAD_F_ML0(hi, lo, t8,   MAD_F(0x09bd7ca0));
  MAD_F_MLA(hi, lo, t9,  -MAD_F(0x0216a2a2));
  MAD_F_MLA(hi, lo, t10,  MAD_F(0x0fdcf549));
  MAD_F_MLA(hi, lo, t11, -MAD_F(0x0cb19346));

  x[1]  = MAD_F_MLZ(hi, lo) + t4;
  x[16] = -x[1];

  MAD_F_ML0(hi, lo, t8,  -MAD_F(0x0fdcf549));
  MAD_F_MLA(hi, lo, t9,  -MAD_F(0x0cb19346));
  MAD_F_MLA(hi, lo, t10, -MAD_F(0x09bd7ca0));
  MAD_F_MLA(hi, lo, t11, -MAD_F(0x0216a2a2));

  x[25] = x[28] = MAD_F_MLZ(hi, lo) + t4;

  MAD_F_ML0(hi, lo, X[1],  -MAD_F(0x0fdcf549));
  MAD_F_MLA(hi, lo, X[7],  -MAD_F(0x0cb19346));
  MAD_F_MLA(hi, lo, X[10], -MAD_F(0x09bd7ca0));
  MAD_F_MLA(hi, lo, X[16], -MAD_F(0x0216a2a2));

  t5 = MAD_F_MLZ(hi, lo) - t6;

  MAD_F_ML0(hi, lo, X[0],   MAD_F(0x0898c779));
  MAD_F_MLA(hi, lo, X[2],   MAD_F(0x04cfb0e2));
  MAD_F_MLA(hi, lo, X[3],   MAD_F(0x0bcbe352));
  MAD_F_MLA(hi, lo, X[5],   MAD_F(0x00b2aa3e));
  MAD_F_MLA(hi, lo, X[6],   MAD_F(0x0e313245));
  MAD_F_MLA(hi, lo, X[8],  -MAD_F(0x03768962));
  MAD_F_MLA(hi, lo, X[9],   MAD_F(0x0f9ee890));
  MAD_F_MLA(hi, lo, X[11], -MAD_F(0x07635284));
  MAD_F_MLA(hi, lo, X[12],  MAD_F(0x0ffc19fd));
  MAD_F_MLA(hi, lo, X[14], -MAD_F(0x0acf37ad));
  MAD_F_MLA(hi, lo, X[15],  MAD_F(0x0f426cb5));
  MAD_F_MLA(hi, lo, X[17], -MAD_F(0x0d7e8807));

  x[2]  = MAD_F_MLZ(hi, lo) + t5;
  x[15] = -x[2];

  MAD_F_ML0(hi, lo, X[0],   MAD_F(0x07635284));
  MAD_F_MLA(hi, lo, X[2],   MAD_F(0x0acf37ad));
  MAD_F_MLA(hi, lo, X[3],   MAD_F(0x03768962));
  MAD_F_MLA(hi, lo, X[5],   MAD_F(0x0d7e8807));
  MAD_F_MLA(hi, lo, X[6],  -MAD_F(0x00b2aa3e));
  MAD_F_MLA(hi, lo, X[8],   MAD_F(0x0f426cb5));
  MAD_F_MLA(hi, lo, X[9],  -MAD_F(0x04cfb0e2));
  MAD_F_MLA(hi, lo, X[11],  MAD_F(0x0ffc19fd));
  MAD_F_MLA(hi, lo, X[12], -MAD_F(0x0898c779));
  MAD_F_MLA(hi, lo, X[14],  MAD_F(0x0f9ee890));
  MAD_F_MLA(hi, lo, X[15], -MAD_F(0x0bcbe352));
  MAD_F_MLA(hi, lo, X[17],  MAD_F(0x0e313245));

  x[3]  = MAD_F_MLZ(hi, lo) + t5;
  x[14] = -x[3];

  MAD_F_ML0(hi, lo, X[0],  -MAD_F(0x0ffc19fd));
  MAD_F_MLA(hi, lo, X[2],  -MAD_F(0x0f9ee890));
  MAD_F_MLA(hi, lo, X[3],  -MAD_F(0x0f426cb5));
  MAD_F_MLA(hi, lo, X[5],  -MAD_F(0x0e313245));
  MAD_F_MLA(hi, lo, X[6],  -MAD_F(0x0d7e8807));
  MAD_F_MLA(hi, lo, X[8],  -MAD_F(0x0bcbe352));
  MAD_F_MLA(hi, lo, X[9],  -MAD_F(0x0acf37ad));
  MAD_F_MLA(hi, lo, X[11], -MAD_F(0x0898c779));
  MAD_F_MLA(hi, lo, X[12], -MAD_F(0x07635284));
  MAD_F_MLA(hi, lo, X[14], -MAD_F(0x04cfb0e2));
  MAD_F_MLA(hi, lo, X[15], -MAD_F(0x03768962));
  MAD_F_MLA(hi, lo, X[17], -MAD_F(0x00b2aa3e));

  x[26] = x[27] = MAD_F_MLZ(hi, lo) + t5;
}


int main(void)
{
	mad_fixed_t in[18] = { 1, 2, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	mad_fixed_t out[36];

	#ifdef __i386
	int i = 20000000, j;
	while(i--) {
		imdct36(in, out);
		for (j = 0; j < 36; ++j) {
			printf("%d ", out[j]);
		}
		printf("\n");
	}
	#else
	while(1) {
		imdct36(in, out);
	}
	#endif

	return 0;
}

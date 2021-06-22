#include "../inc/core.h"
#define min(a,b) (((a)<(b))?(a):(b))
# define LIN_MAT_NULL (t_mat) {NUL, 0, 0}

typedef struct	s_mat
{
	double		*m;
	t_size		x;
	t_size		y;
}				t_mat;

void mxm_block_reorder_reuse_unroll_16(
	double *C,
	const double *A,
	const double *B,
	int m,
	int n,
	int p)
{
	int i, j, k, ii, jj, kk, Aik, bs = 128;

	for(ii = 0; ii < m; ii += bs)
		for(kk = 0; kk < n; kk += bs)
			for(jj = 0; jj < p; jj += bs)
				for(i = ii; i < min(m, ii+bs); i++)
					for(k = kk; k < min(n, kk+bs); k++)
					{
						Aik = A[n*i+k];
						for(j = jj; j < min(p, jj+bs); j+=16)
						{
							C[p*i+j] += Aik * B[p*k+j];
							C[p*i+j+1] += Aik * B[p*k+j+1];
							C[p*i+j+2] += Aik * B[p*k+j+2];
							C[p*i+j+3] += Aik * B[p*k+j+3];
							C[p*i+j+4] += Aik * B[p*k+j+4];
							C[p*i+j+5] += Aik * B[p*k+j+5];
							C[p*i+j+6] += Aik * B[p*k+j+6];
							C[p*i+j+7] += Aik * B[p*k+j+7];
							C[p*i+j+8] += Aik * B[p*k+j+8];
							C[p*i+j+9] += Aik * B[p*k+j+9];
							C[p*i+j+10] += Aik * B[p*k+j+10];
							C[p*i+j+11] += Aik * B[p*k+j+11];
							C[p*i+j+12] += Aik * B[p*k+j+12];
							C[p*i+j+13] += Aik * B[p*k+j+13];
							C[p*i+j+14] += Aik * B[p*k+j+14];
							C[p*i+j+15] += Aik * B[p*k+j+15];
						}
					}
}

t_mat	lin_mat_new(t_size x, t_size y)
{
	t_mat	new;

	new.m = (double *)malloc(sizeof(double) * x * y);
	if (!new.m)
		exit(-1);
	new.x = x;
	new.y = y;
	return (new);
}

int main(void)
{
	t_mat	a;
	t_mat	b;
	t_mat	res;

	a = lin_mat_new(4, 4);
	t_size i = 0;
	while (i < 16)
	{
		a.m[i] = i + 1;
		i++;
	}

	b = lin_mat_new(4, 4);
	i = 0;
	while (i < 16)
	{
		b.m[i] = i + 1;
		i++;
	}

	res = lin_mat_new(4, 4);
	mxm_block_reorder_reuse_unroll_16(res.m, a.m, b.m, 16, 16, 16);

	i = 0;
	while (i < 16)
	{
		printf("%lf\n", res.m[i]);
		i++;
	}
}
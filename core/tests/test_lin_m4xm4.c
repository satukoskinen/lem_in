#include "../inc/core.h"

t_ssize	lin_m4_cmp(t_mat4 a, t_mat4 b)
{
	if (mcmp(a.m, b.m, sizeof(double) * 16) == 0)
		return (1);
	return (0);
}

int main(void)
{
	t_mat4	mat_1;
	t_mat4	mat_2;
	t_mat4	answer;

	mat_1 = (t_mat4){{
			1, 2, 3, 4,
			5, 6, 7, 8,
			9, 10, 11, 12,
			13, 14, 15, 16}};
	mat_2 = (t_mat4){{
			1, 2, 3, 4,
			5, 6, 7, 8,
			9, 10, 11, 12,
			13, 14, 15, 16}};
	answer = (t_mat4){{
			90, 100, 110, 120,
			202, 228, 254, 280,
			314, 356, 398, 440,
			426, 484, 542, 600}};
	const t_mat4	res = lin_m4xm4_r(&mat_1, &mat_2);
	if (lin_m4_cmp(answer, res) == 1)
		print("Test ok!\n");
	lin_m4_print(&res);
}

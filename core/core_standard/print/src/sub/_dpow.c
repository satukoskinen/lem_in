/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

double	_dpow(double base, int power)
{
	double	result;

	result = 1.0;
	while (power > 0)
	{
		result *= base;
		power--;
	}
	return (result);
}

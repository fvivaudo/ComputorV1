/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 17:26:39 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/04/01 17:26:40 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <comput.h>

void	ft_deltamin2(double d, double r, double **nums)
{
	r = (-nums[1][0]) / (2 * nums[2][0]);
	if (r == 0)
		r = 0;
	printf("delta < 0\n");
	printf("(-b - root(b^2 - 4ac)) / 2a = (%g - ", -nums[1][0]);
	printf("root(%g - 4 *", ft_pow(nums[1][0], 2));
	printf(" (%g * %g))) / (2 * %g)\n", nums[0][0], nums[2][0], nums[2][0]);
	printf("(-b - root(b^2 - 4ac)) / 2a = (%g - ", -nums[1][0]);
	printf("root(%g -", ft_pow(nums[1][0], 2));
	printf(" %g)) / %g\n", 4 * nums[0][0] * nums[2][0], 2 * nums[2][0]);
	printf("(-b - root(b^2 - 4ac)) / 2a = (%g - ", -nums[1][0]);
	printf("%gi)", ft_root(-d));
	printf(" / %g\n", 2 * nums[2][0]);
	printf("Result 1 : %g - %gi\n", r, (ft_root(-d)) / (2 * nums[2][0]));
	printf("(-b + root(b^2 - 4ac)) / 2a = (%g + ", -nums[1][0]);
	printf("root(%g - 4 *", ft_pow(nums[1][0], 2));
	printf(" (%g * %g))) / (2 * %g)\n", nums[0][0], nums[2][0], nums[2][0]);
	printf("(-b + root(b^2 - 4ac)) / 2a = (%g + ", -nums[1][0]);
	printf("root(%g -", ft_pow(nums[1][0], 2));
	printf(" %g)) / %g\n", 4 * nums[0][0] * nums[2][0], 2 * nums[2][0]);
	printf("(-b + root(b^2 - 4ac)) / 2a = (%g + ", -nums[1][0]);
	printf("%gi)", ft_root(-d));
	printf(" / %g\n", 2 * nums[2][0]);
	printf("Result 2 : %g + %gi\n", r, (ft_root(-d)) / (2 * nums[2][0]));
}

void	ft_deltasup2(double d, double **nums)
{
	printf("delta > 0\n");
	printf("(-b - root(b^2 - 4ac)) / 2a = (%g - ", -nums[1][0]);
	printf("root(%g - 4 *", ft_pow(nums[1][0], 2));
	printf(" (%g * %g))) / (2 * %g)\n", nums[0][0], nums[2][0], nums[2][0]);
	printf("(-b - root(b^2 - 4ac)) / 2a = (%g - ", -nums[1][0]);
	printf("root(%g -", ft_pow(nums[1][0], 2));
	printf(" %g)) / %g\n", 4 * nums[0][0] * nums[2][0], 2 * nums[2][0]);
	printf("(-b - root(b^2 - 4ac)) / 2a = (%g - ", -nums[1][0]);
	printf("%g)", ft_root(d));
	printf(" / %g\n", 2 * nums[2][0]);
	printf("Result 1 : %g\n", (-nums[1][0] - ft_root(d)) / (2 * nums[2][0]));
	printf("(-b + root(b^2 - 4ac)) / 2a = (%g + ", -nums[1][0]);
	printf("root(%g - 4 *", ft_pow(nums[1][0], 2));
	printf(" (%g * %g))) / (2 * %g)\n", nums[0][0], nums[2][0], nums[2][0]);
	printf("(-b + root(b^2 - 4ac)) / 2a = (%g + ", -nums[1][0]);
	printf("root(%g -", ft_pow(nums[1][0], 2));
	printf(" %g)) / %g\n", 4 * nums[0][0] * nums[2][0], 2 * nums[2][0]);
	printf("(-b + root(b^2 - 4ac)) / 2a = (%g + ", -nums[1][0]);
	printf("%g)", ft_root(d));
	printf(" / %g\n", 2 * nums[2][0]);
	printf("Result 2 : %g\n", (-nums[1][0] + ft_root(d)) / (2 * nums[2][0]));
}

void	ft_deltaequal2(double **nums)
{
	printf("delta = 0\n");
	printf("-b / 2a = %g / (2 * %g)\n", -nums[1][0], nums[2][0]);
	printf("-b / 2a = %g / %g\n", -nums[1][0], (2 * nums[2][0]));
	printf("Result : %g\n", (-nums[1][0]) / (2 * nums[2][0]));
}

void	ft_solve2(double **nums)
{
	double	d;
	double	r;

	r = 0;
	d = ft_pow(nums[1][0], 2) - (4 * nums[0][0] * nums[2][0]);
	if (d < 0)
		ft_deltamin2(d, r, nums);
	else if (d == 0)
		ft_deltaequal2(nums);
	else
		ft_deltasup2(d, nums);
	return ;
}

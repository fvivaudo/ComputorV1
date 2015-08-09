/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 11:21:29 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/03/24 11:21:31 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <comput.h>

char	*ft_solve0(double **nums)
{
	if (nums[0][1] == nums[0][0])
		return ("All real numbers");
	return ("No solution");
}

double	ft_solve1(double **nums, int degree)
{
	int		i;
	int		y;
	double	divi;

	i = 0;
	y = 0;
	nums[i][1] -= nums[i][0];
	nums[i][0] = 0;
	divi = nums[1][0];
	while (i <= degree)
	{
		nums[i][0] /= divi;
		nums[i][1] /= divi;
		++i;
	}
	if (nums[0][1] == 0)
		nums[0][1] = 0;
	return (nums[0][1]);
}

void	ft_check_input(char *av)
{
	int		i;

	i = 0;
	if (ft_ldiff("0123456789X/=*+-^ ", av) != -1)
		ft_error("Some of the characters you've entered are incorect.");
	if (ft_count(av, '=') < 1)
		ft_error("You need at least one '=' to form an equation.");
	if (ft_count(av, '=') > 1)
		ft_error("You need do not need more than one '=' to form an equation.");
}

int		main(int ac, char **av)
{
	double	**nums;
	int		degree;

	degree = 0;
	if (ac != 2)
		ft_error("It seems the number of arguments is incorrect.");
	ft_check_input(av[1]);
	nums = ft_set_nums(av[1], &degree);
	printf("Reduced form : ");
	if (degree == 0)
		printf("%g * X^0 = %g * X^0\n", nums[0][0], nums[0][1]);
	else
		ft_print_reduce(0, 0, degree, nums);
	printf("Equation degree : %d\n", degree);
	if (degree == 0)
		printf("Result : %s\n", ft_solve0(nums));
	else if (degree == 1)
		printf("Result : %g\n", ft_solve1(nums, degree));
	else if (degree == 2)
		ft_solve2(nums);
	else
		printf("Degree too high. Sorry :(\n");
	exit(0);
	return (0);
}

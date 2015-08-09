/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_reduce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 17:30:21 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/04/01 17:30:21 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <comput.h>

double	**ft_reduce(double **nums, int *degree, int max_degree)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i <= max_degree)
	{
		if ((nums[i][0] || nums[i][1]) && (nums[i][0] != nums[i][1]))
			*degree = i;
		nums[i][0] -= nums[i][1];
		if (nums[i][0] < 0)
			nums[i][2] = '-';
		else if (nums[i][0] >= 0)
			nums[i][2] = '+';
		nums[i][1] = 0;
		nums[i][3] = 0;
		++i;
	}
	return (nums);
}

int		ft_print_reduce2(int i, int y, int degree, double **nums)
{
	int		z;

	z = 1;
	while ((i + z) <= degree && nums[i + z][y + 2] != 0)
	{
		if (nums[i + z][y + 2] != 0)
		{
			printf(" %c ", (char)nums[i + z][y + 2]);
			return (0);
		}
		++z;
	}
	if (y == 1)
	{
		printf("\n");
		return (1);
	}
	return (0);
}

void	ft_print_reduce(int i, int y, int degree, double **nums)
{
	int		first;

	first = 1;
	while (i <= degree)
	{
		if (i <= degree || y == 1)
		{
			if (first == 1)
				printf("%.3g * X^%d", nums[i][y], i), --first;
			else
				printf("%.3g * X^%d", ft_abs(nums[i][y]), i);
			if (ft_print_reduce2(i, y, degree, nums))
				return ;
		}
		if (i == degree && y == 0)
			printf(" = ");
		++i;
		if ((i - 1) == degree && y < 1)
			i = 0, ++y, ++first;
	}
}

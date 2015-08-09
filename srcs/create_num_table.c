/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_num_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 17:16:19 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/04/01 17:16:21 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <comput.h>

double	**ft_set_nums(char *av, int *degree)
{
	int		i;
	int		equal;
	int		max_degree;
	double	**nums;
	char	**tab;

	i = 0;
	tab = ft_strsplitspace(av);
	while (tab[i])
	{
		if (tab[i][0] == '=')
			break ;
		++i;
	}
	equal = i;
	max_degree = ft_find_max_degree(tab);
	if (max_degree > 1000)
		ft_error("Don't fuck with me.");
	nums = ft_nums_init(max_degree);
	nums = ft_fill_nums(tab, nums, equal);
	nums = ft_reduce(nums, degree, max_degree);
	return (nums);
}

double	**ft_nums_init(int max_degree)
{
	double	**nums;
	int		i;

	i = 0;
	nums = (double**)malloc(sizeof(double*) * (max_degree + 1));
	nums[max_degree] = 0;
	while (i <= max_degree + 1)
		nums[i] = (double*)malloc(sizeof(double) * 5), ++i;
	i = 0;
	while (i <= max_degree)
	{
		ft_bzero(nums[i], 5 * sizeof(double));
		++i;
	}
	i = 0;
	return (nums);
}

double	**ft_fill_nums2(char **tab, double **nums, int equal, int i)
{
	int		tmp;

	if (i > equal)
	{
		if ((tmp = ft_atoi(tab[i + 2] + 2)) < 0)
			nums[0][1] += ft_pow((double)ft_atoi(tab[i]), tmp);
		else
			nums[tmp][1] += (double)ft_atoi(tab[i]);
		if ((i - 1) >= 0 && tab[i - 1][0] == '-')
			nums[tmp][1] *= -1;
	}
	else
	{
		if ((tmp = ft_atoi(tab[i + 2] + 2)) < 0)
			nums[0][0] += ft_pow((double)ft_atoi(tab[i]), tmp);
		else
			nums[tmp][0] += (double)ft_atoi(tab[i]);
		if ((i - 1) >= 0 && tab[i - 1][0] == '-')
			nums[tmp][0] *= -1;
	}
	return (nums);
}

double	**ft_fill_nums(char **tab, double **nums, int equal)
{
	int		i;

	i = 0;
	while (tab[i + 1])
	{
		if (ft_atoi(tab[i]) != 0)
			nums = ft_fill_nums2(tab, nums, equal, i);
		++i;
	}
	return (nums);
}

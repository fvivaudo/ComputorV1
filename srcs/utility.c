/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 17:26:06 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/04/01 17:26:07 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <comput.h>

double	ft_abs(double num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

double	ft_pow(double num, int power)
{
	double	ret;

	ret = 1;
	while (power > 0)
		ret *= num, --power;
	while (power < 0)
		ret /= num, ++power;
	return (ret);
}

double	ft_root(double num)
{
	double	new_ret;
	double	ret;
	double	h;
	double	low;

	ret = 0;
	while ((ret * ret) < num)
		++ret;
	if ((ret * ret) == num)
		return (ret);
	h = ret;
	low = --ret;
	new_ret = -1;
	while (new_ret != ret)
	{
		new_ret = ret;
		if ((ret * ret) < num)
			low = ret;
		else
			h = ret;
		ret = (ret * ret) < num ? ret + (h - low) / 2 : ret - (h - low) / 2;
	}
	return (ret);
}

void	ft_error(char *str)
{
	ft_putendl(str);
	ft_putendl("Please, reformulate your input.");
	exit (0);
}

int		ft_find_max_degree(char **tab)
{
	int		i;
	int		max;

	max = 0;
	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == 'X' && ft_atoi(tab[i] + 2) > max)
			max = ft_atoi(tab[i] + 2);
		++i;
	}
	return (max);
}

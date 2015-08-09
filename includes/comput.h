/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 11:12:29 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/03/26 11:13:56 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUT_H
# define COMPUT_H

# include <stdio.h>
# include <stdlib.h>
# include <libft.h>

double		ft_abs(double num);
double		ft_pow(double num, int power);
double		ft_root(double num);
void		ft_error(char *str);
double		**ft_reduce(double **nums, int *degree, int max_degree);
char		*ft_solve0(double **nums);
double		ft_solve1(double **nums, int degree);
void		ft_deltamin2(double d, double r, double **nums);
void		ft_deltasup2(double d, double **nums);
void		ft_deltaequal2(double **nums);
void		ft_solve2(double **nums);
int			ft_find_max_degree(char **tab);
double		**ft_nums_init(int max_degree);
double		**ft_fill_nums2(char **tab, double **nums, int equal, int i);
double		**ft_fill_nums(char **tab, double **nums, int equal);
int			ft_print_reduce2(int i, int y, int degree, double **nums);
void		ft_print_reduce(int i, int y, int degree, double **nums);
double		**ft_set_nums(char *av, int *degree);
void		ft_check_input(char *av);

#endif

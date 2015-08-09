/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:37:00 by fvivaudo          #+#    #+#             */
/*   Updated: 2014/11/09 09:58:09 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_strclr(char *s)
{
	if (s)
	{
		while (*s != '\0')
		{
			*s = '\0';
			s++;
		}
	}
}

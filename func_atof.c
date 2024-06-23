/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_atof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:54:16 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/16 20:56:30 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

double	ft_atof_loop(const char *str, double d, double place)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			die("error: invalid parameters");
		d = d + (*str - '0') * place;
		if (d > 2.0)
			die("error: invalid parameters");
		str++;
		place *= 0.1;
	}
	return (d);
}

double	ft_atof(const char *str)
{
	double	d;
	double	symbol;

	d = 0;
	symbol = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			symbol = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		d = d * 10 + (*str - '0');
		if (d > 2.0)
			die("error2: invalid parameters");
		str++;
	}
	if (*str == '.' || !*str)
		d = ft_atof_loop(str + 1, d, 0.1);
	else
		die("error: invalid parameters");
	return (d * symbol);
}

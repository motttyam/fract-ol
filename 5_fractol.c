/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_fractol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:11:40 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/23 15:37:20 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c, int maxiter)
{
	int			i;
	t_complex	z;

	i = 0;
	z.re = 0.0;
	z.im = 0.0;
	while (i < maxiter)
	{
		z = comp_sum(comp_mul(z, z), c);
		if (comp_abs(z) > 4.0)
			return (i);
		i++;
	}
	return (maxiter);
}

int	julia(t_complex z, t_complex c, int maxiter)
{
	int	i;

	i = 0;
	while (i < maxiter)
	{
		z = comp_sum(comp_mul(z, z), c);
		if (comp_abs(z) > 4.0)
			return (i);
		i++;
	}
	return (maxiter);
}

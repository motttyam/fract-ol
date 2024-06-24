/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:50:16 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/24 21:00:19 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	comp_sum(t_complex x, t_complex y)
{
	t_complex	res;

	res.re = x.re + y.re;
	res.im = x.im + y.im;
	return (res);
}

t_complex	comp_mul(t_complex x, t_complex y)
{
	t_complex	res;

	res.re = (x.re * y.re) - (x.im * y.im);
	res.im = (x.re * y.im) + (x.im * y.re);
	return (res);
}

t_complex	burning_comp_mul(t_complex x, t_complex y)
{
	t_complex	res;

	res.re = (x.re * y.re) - (x.im * y.im);
	res.im = -fabs((x.re * y.im) + (x.im * y.re));
	return (res);
}

double	comp_abs(t_complex z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}

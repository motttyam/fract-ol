/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_rendor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:11:37 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/23 15:55:46 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rendor_fractol(t_data *vars)
{
	if (vars->type == MANDELBROT)
		rendor_mandelbort(vars);
	if (vars->type == JULIA)
		rendor_julia(vars);
	return ;
}

void	rendor_mandelbort(t_data *vars)
{
	int			i;
	int			j;
	t_complex	c;
	int			count;

	j = 0;
	vars->dx = (vars->x_fin - vars->x_start) / WIDTH;
	vars->dy = (vars->y_fin - vars->y_start) / HEIGHT;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			c.re = vars->x_start + i * vars->dx;
			c.im = vars->y_start + j * vars->dy;
			count = mandelbrot(c, vars->iter_max);
			put_color_up_to_count(count, vars, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_ptr, 0, 0);
}

void	rendor_julia(t_data *vars)
{
	int			i;
	int			j;
	t_complex	z;
	int			count;

	j = 0;
	vars->dx = (vars->x_fin - vars->x_start) / WIDTH;
	vars->dy = (vars->y_fin - vars->y_start) / HEIGHT;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			z.re = vars->x_start + i * vars->dx;
			z.im = vars->y_start + j * vars->dy;
			count = julia(z, vars->c, vars->iter_max);
			put_color_up_to_count(count, vars, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_ptr, 0, 0);
}

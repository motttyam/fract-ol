/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:00:36 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/24 21:10:15 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_up_to_count(int count, t_data *vars, int x, int y)
{
	int	r;
	int	g;
	int	b;
	int	color;

	if (count == vars->iter_max)
	{
		r = 0;
		g = 0;
		b = 0;
	}
	else
	{
		r = sin(0.6 * count + 0) * 127 + 128 + vars->color;
		g = sin(0.6 * count + 2 * M_PI / 3) * 127 + 128 + vars->color;
		b = sin(0.6 * count + 4 * M_PI / 3) * 127 + 128 + vars->color;
	}
	color = (r << 16 | g << 8 | b);
	my_mlx_pixel_put(vars, x, y, color);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

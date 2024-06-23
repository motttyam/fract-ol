/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:19:53 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/23 15:53:34 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int mousecode, int x, int y, t_data *vars)
{
	if (mousecode == 4)
		zoom(vars, 0.90, (double)x, (double)y);
	else if (mousecode == 5)
		zoom(vars, 1.10, (double)x, (double)y);
	mlx_clear_window(vars->mlx, vars->win);
	rendor_fractol(vars);
	return (0);
}

void	zoom(t_data *f, double zoom, double x, double y)
{
	double	new_width;
	double	new_height;
	double	mouse_x;
	double	mouse_y;

	new_width = (f->x_fin - f->x_start) * zoom;
	new_height = (f->y_start - f->y_fin) * zoom;
	mouse_x = f->x_start + (x / WIDTH) * (f->x_fin - f->x_start);
	mouse_y = f->y_start - (y / HEIGHT) * (f->y_start - f->y_fin);
	f->x_start = mouse_x - ((mouse_x - f->x_start) * zoom);
	f->x_fin = f->x_start + new_width;
	f->y_start = mouse_y + ((f->y_start - mouse_y) * zoom);
	f->y_fin = f->y_start - new_height;
}

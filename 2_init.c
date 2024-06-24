/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:48:19 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/24 20:25:30 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_data *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->img_ptr = NULL;
	vars->color = 5;
	vars->addr = NULL;
	vars->type = 0;
	vars->c.re = 0.0;
	vars->c.im = 0.0;
	vars->dx = 0.0;
	vars->dy = 0.0;
	vars->x_start = -2.0;
	vars->y_start = 2.0;
	vars->x_fin = 2.0;
	vars->y_fin = -2.0;
	vars->iter_max = 100;
}

void	system_init(t_data *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		die("Error initializing mlx");
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fractol");
	if (vars->win == NULL)
		die("Error creating window");
	vars->img_ptr = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (vars->img_ptr == NULL)
		die("Error creating image");
	vars->addr = mlx_get_data_addr(vars->img_ptr, &(vars->bits_per_pixel),
			&(vars->line_length), &(vars->endian));
	if (vars->addr == NULL)
		die("Error getting image address");
}

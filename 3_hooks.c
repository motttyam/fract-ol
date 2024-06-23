/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:25:57 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/23 15:50:34 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	change_iter(t_data *f, int code)
{
	if (code == 13 && f->iter_max < 1000)
		f->iter_max += 100;
	else if (code == 1 && f->iter_max > 100)
		f->iter_max -= 100;
	return ;
}

void	move(t_data *f, int code, double width, double height)
{
	width = f->x_fin - f->x_start;
	height = f->y_start - f->y_fin;
	if (code == 123)
	{
		f->x_start -= width * 0.1;
		f->x_fin -= width * 0.1;
	}
	if (code == 124)
	{
		f->x_start += width * 0.1;
		f->x_fin += width * 0.1;
	}
	if (code == 125)
	{
		f->y_start -= height * 0.1;
		f->y_fin -= height * 0.1;
	}
	if (code == 126)
	{
		f->y_start += height * 0.1;
		f->y_fin += height * 0.1;
	}
	mlx_clear_window(f->mlx, f->win);
}

int	key_press(int keycode, t_data *vars)
{
	if (keycode == 53)
		ft_close(vars);
	if (keycode == 13 || keycode == 1)
		change_iter(vars, keycode);
	if (keycode >= 123 && keycode <= 126)
		move(vars, keycode, 0, 0);
	rendor_fractol(vars);
	return (0);
}

void	hooks(t_data *vars)
{
	mlx_hook(vars->win, ON_DESTROY, 0, ft_close, vars);
	mlx_key_hook(vars->win, key_press, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
}

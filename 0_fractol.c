/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_fractol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:47:28 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/23 15:51:03 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_data	vars;

	vars = handle_args(argc, argv);
	if (vars.type == 0)
		return (0);
	system_init(&vars);
	hooks(&vars);
	rendor_fractol(&vars);
	mlx_loop(vars.mlx);
	return (0);
}

// int	loop_hook(t_data *data)
// {
// 	static int	frame = 0;

// 	frame++;
// 	if (frame % 30 == 0)
// 	{
// 		rendor_fractol(data);
// 	}
// 	return (0);
// }
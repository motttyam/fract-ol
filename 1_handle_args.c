/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_handle_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:46:53 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/23 15:55:18 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	handle_args(int ac, char **av)
{
	t_data	vars;

	fractol_init(&vars);
	if (ac == 2)
	{
		if (!ft_strncmp(av[1], "Julia", 5))
			vars.type = JULIA;
		else if (!ft_strncmp(av[1], "Mandelbrot", 10))
			vars.type = MANDELBROT;
		else
			print_usage();
	}
	else if (ac == 4)
	{
		if (ft_strncmp(av[1], "Julia", 5))
			print_usage();
		vars.type = JULIA;
		vars.c.re = ft_atof(av[2]);
		vars.c.im = ft_atof(av[3]);
	}
	else
		print_usage();
	return (vars);
}

void	print_usage(void)
{
	ft_putendl_fd("Common Usage:", 2);
	ft_putendl_fd("\nYou can select two fractals", 2);
	ft_putendl_fd("\n\tMandelbrot Set", 2);
	ft_putendl_fd("\t  Julia Set", 2);
	ft_putendl_fd("\nIf you select Julia, you can select two parameters.", 2);
	ft_putendl_fd("Each parameters must satisfy following condition", 2);
	ft_putendl_fd("\n\t-2.0 <= c_re, c_im <= 2.0", 2);
	ft_putendl_fd("\nexample:\t", 2);
	ft_putendl_fd("\t./fractol Julia -0.8 0.15\n", 2);
	ft_putendl_fd("\t./fractol Mandelbrot\n", 2);
	ft_putendl_fd("\t./fractol Burningfire\n", 2);
	ft_putendl_fd("\n\nAdditonal Usage:", 2);
	ft_putendl_fd("You can use the arroy key(→↑↓←) to move within the window\n",
		2);
	ft_putendl_fd("You can press 'w' to see a more detailed fractal image", 2);
	ft_putendl_fd("And 's' to see a less detailed one.\n", 2);
}

void	die(char *str)
{
	ft_putendl_fd(str, 1);
	print_usage();
	exit(0);
}

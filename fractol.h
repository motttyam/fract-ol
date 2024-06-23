/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:57:05 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/23 15:57:26 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 640
# define HEIGHT 640

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

	int			type;
	t_complex	c;
	double		x_start;
	double		y_start;
	double		x_fin;
	double		y_fin;
	double		dx;
	double		dy;
	int			iter_max;
	int			color;

}				t_data;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	JULIA = -1,
	MANDELBROT = -2
};

int				loop_hook(t_data *data);
// handle_args.c
t_data			handle_args(int ac, char **av);
void			print_usage(void);
void			die(char *str);

// init.c
void			fractol_init(t_data *vars);
void			system_init(t_data *vars);

// hooks.c
void			hooks(t_data *vars);
int				key_press(int keycode, t_data *vars);
int				ft_close(t_data *vars);

// rendor.c
void			rendor_fractol(t_data *vars);
void			rendor_mandelbort(t_data *vars);
int				mandelbrot(t_complex c, int maxiter);

// fractol.c
void			rendor_julia(t_data *vars);
int				julia(t_complex z, t_complex c, int maxiter);

///////////////////////// funcs /////////////////////////
// func_utlis.c
size_t			ft_strlen(const char *s);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

// func_atof.c
double			ft_atof(const char *str);

// func_complex.c
t_complex		comp_sum(t_complex x, t_complex y);
t_complex		comp_mul(t_complex x, t_complex y);
double			comp_abs(t_complex z);

// func_color.c
void			put_color_up_to_count(int count, t_data *vars, int i, int j);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

// func_zoom.c
void			zoom(t_data *f, double zoom, double x, double y);
int				mouse_hook(int mousecode, int x, int y, t_data *vars);

#endif
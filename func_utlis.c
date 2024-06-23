/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utlis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:21:06 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/16 20:58:10 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	if (n == 0)
		return (0);
	result = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		result = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (s1[i] != s2[i])
			return (result);
		i++;
	}
	return (result);
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	length;
	size_t	already_written;
	size_t	write_to_byte;

	if (!s)
		return ;
	length = ft_strlen(s);
	already_written = 0;
	write_to_byte = 0;
	while (length > write_to_byte)
	{
		write_to_byte = length - already_written;
		if (write_to_byte > INT_MAX)
		{
			write(fd, s + already_written, 10);
		}
		else
			write(fd, s + already_written, write_to_byte);
	}
}

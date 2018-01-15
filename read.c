/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:22:52 by anestor           #+#    #+#             */
/*   Updated: 2018/01/15 20:45:07 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		read_fdf(char *file, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		n;

	allocate_dots(file, fdf);
	if ((fd = open(file, O_RDWR)) < 0)
		fdf_exit("No such file or directory\n");
	n = 0;
	while (get_next_line(fd, &line) > 0)
		read_lines(line, fdf, &n);
	close(fd);
	fdf->win_h = WIN_H;
	fdf->win_w = WIN_W;
	fdf->scale = 1;
	fdf->z_scale = 1;
	fdf->x_angle = -45;
	fdf->y_angle = 45;
	fdf->z_angle = -30;
	return (0);
}

void	allocate_dots(char *file, t_fdf *fdf)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDWR)) < 0)
		fdf_exit("No such file or directory\n");
	while (get_next_line(fd, &line) > 0)
	{
		fdf->grid_p_w = ft_count_words(line, ' ');
		fdf->grid_p_h++;
		free(line);
	}
	close(fd);
	if ((fdf->dot = (t_dot *)ft_memalloc(sizeof(t_dot) *
			(fdf->grid_p_h * fdf->grid_p_w))) == NULL)
		fdf_exit("Out of memory\n");
	if ((fdf->p_dot = (t_dot *)ft_memalloc(sizeof(t_dot) *
			(fdf->grid_p_h * fdf->grid_p_w))) == NULL)
		fdf_exit("Out of memory\n");
}

void	read_lines(char *line, t_fdf *fdf, int *n)
{
	int		i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		Z(*n) = ft_atoi(&line[i]);
		while (line[i] != ' ' && line[i] != ',' && line[i] != '\0')
			i++;
		if (line[i] == ',')
		{
			i += 3;
			COLOR(*n) = ft_atoi_base(&line[i], 16);
			while (line[i] != ' ' && line[i] != '\0')
				i++;
		}
		else
			COLOR(*n) = 0xffffff;
		*n = *n + 1;
	}
}

void	first_scale(t_fdf *fdf)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	pre_render(fdf);
	while (y != fdf->grid_p_h)
	{
		x = 0;
		while (x != fdf->grid_p_w)
		{
			if (PX(i) < 0 || PY(i) < 0)
			{
				fdf->scale -= 0.1;
				pre_render(fdf);
			}
			x++;
			i++;
		}
		y++;
	}
}

void	pre_render(t_fdf *fdf)
{
	scale_and_position(fdf);
	rotate_x(fdf);
	rotate_y(fdf);
	rotate_z(fdf);
}

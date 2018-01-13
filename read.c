/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:22:52 by anestor           #+#    #+#             */
/*   Updated: 2018/01/13 22:03:30 by anestor          ###   ########.fr       */
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
	{
		read_lines(line, fdf, &n);
	}
	close(fd);
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
	set_height_width(fdf);
	printf("p_h: %d, p_w: %d\n", fdf->grid_p_h, fdf->grid_p_w); //debugging
	printf("h: %d, w: %d\n", fdf->grid_h, fdf->grid_w); //debugging
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
	//	i += ft_num_len(Z(*n));
//		printf("num_len :%d\n", ft_num_len(Z(*n)));
	//	printf("z %d\n", Z(*n));
		if (line[i] == ',')
		{
			i += 3;
			COLOR(*n) = ft_atoi_base(&line[i], 16);
		//	printf("color: %X\n", COLOR(*n));
		//	printf("color: %X\n", ft_atoi_base(&line[i], 16));
			while (line[i] != ' ' && line[i] != '\0')
				i++;
		}
		else
			COLOR(*n) = 0xffffff;
		*n = *n + 1;
	}
//	printf("n test: %d\n", *n);
}

void	set_height_width(t_fdf *fdf)
{
	fdf->win_h = 1000;
	fdf->win_w = 1000;
	fdf->grid_h = fdf->win_h / (GREATER(fdf->grid_p_w, fdf->grid_p_h));
	fdf->grid_w = fdf->grid_h;
}
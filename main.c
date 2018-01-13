/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:22:11 by anestor           #+#    #+#             */
/*   Updated: 2018/01/13 22:30:49 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	make_grid(t_fdf *fdf)
{
	int		x;
	int		y;
	int		xx;
	int		yy;
	int		i;

	y = 0;
	i = 0;
	while (y != fdf->grid_p_h)
	{
	//	yy = (fdf->grid_w - fdf->grid_h) * 10 + (fdf->grid_h / 2) * y;
		yy = (fdf->grid_h / 2) * y;
		xx = fdf->win_w / 2 - (fdf->grid_w / 2 * y);
		x = 0;
		while (x != fdf->grid_p_w)
		{
			X(i) = xx + (x * (fdf->grid_w / 2));
			yy += fdf->grid_h / 2;
			Y(i) = yy - Z(i) * 4;
			x++;
			i++;
		}
		y++;
	}

	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->dot[i].x, fdf->dot[i].y, COLOR(i));
//		printf("x: %d, y: %d\n", fdf->dot[i].x, fdf->dot[i].y);
	//	printf("x: %d, y: %d\n", xxx[i], yyy[i]);
		i++;
	}

}

void	draw_grid(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, X(i), Y(i), COLOR(i));
		i++;
	}
	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w - fdf->grid_p_w)
	{
		ft_draw_vector(fdf->dot[i], fdf->dot[i + fdf->grid_p_w], fdf->mlx, fdf->win);
		i++;
	}
	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		if (((i + 1) % fdf->grid_p_w))
			ft_draw_vector(fdf->dot[i], fdf->dot[i + 1], fdf->mlx, fdf->win);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		if ((fdf = ft_memalloc(sizeof(t_fdf))) == NULL)
			fdf_exit("Out of memory\n");
		read_fdf(argv[1], fdf);

		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, fdf->win_w, fdf->win_h, "fdf");
		make_grid(fdf);
		draw_grid(fdf);
		mlx_loop(fdf->mlx);
	}
	return(0);
}

int		fdf_exit(char *text)
{
	write(1, text, ft_strlen(text));
	exit(1);
}

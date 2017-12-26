/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:22:11 by anestor           #+#    #+#             */
/*   Updated: 2017/12/26 19:32:44 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <time.h>

void	make_grid(t_fdf *fdf);
void	rotate_z(t_fdf *fdf);
void	rotate_y(t_fdf *fdf);
void	rotate_x(t_fdf *fdf);
void	draw_grid(t_fdf *fdf);
void	heigth_set(t_fdf *fdf);

int		key_hook_test(int keycode, t_fdf *fdf)
{
	if (keycode == 123)
	{
		//while (keycode == 123)
		fdf->angle = fdf->angle - 5;
		mlx_clear_window(fdf->mlx, fdf->win);
		make_grid(fdf);
	//	heigth_set(fdf);
	//	rotate_y(fdf);
		rotate_z(fdf);
		heigth_set(fdf);
		draw_grid(fdf);
	}
	if (keycode == 124)
	{
		fdf->angle = fdf->angle + 5;
		mlx_clear_window(fdf->mlx, fdf->win);
		make_grid(fdf);
	//	heigth_set(fdf);
	//	rotate_y(fdf);
		rotate_z(fdf);
		heigth_set(fdf);
		draw_grid(fdf);
	}
	if (keycode == 126)
	{
	//	fdf->grid_h++;
		fdf->angle = fdf->angle + 5;
		mlx_clear_window(fdf->mlx, fdf->win);
		make_grid(fdf);
		rotate_x(fdf);
		rotate_y(fdf);
		heigth_set(fdf);
		draw_grid(fdf);
	}
	if (keycode == 125)
	{
	//	fdf->grid_h--;
		fdf->angle = fdf->angle - 5;
		mlx_clear_window(fdf->mlx, fdf->win);
		make_grid(fdf);
		rotate_x(fdf);
		rotate_y(fdf);
		heigth_set(fdf);
		draw_grid(fdf);
	}
	if (keycode == 53)
		exit(0);
	printf("%d\n", keycode);
	return (0);
}

void	make_grid(t_fdf *fdf)
{
	int		x;
	int		y;
	int		xx;
	int		yy;
	int		i;

	y = 0;
	i = 0;
	while (y != fdf->grid_mh)
	{
	//	yy = (fdf->grid_w - fdf->grid_h) * 10 + (fdf->grid_h / 2) * y;
		yy = (fdf->grid_h / 2) * y;
		xx = fdf->win_w / 2 - (fdf->grid_w / 2 * y);
		x = 0;
		while (x != fdf->grid_mw)
		{
			X(i) = xx + (x * (fdf->grid_w / 2));
			yy += fdf->grid_h / 2;
			Y(i) = yy;
			x++;
			i++;
		}
		y++;
	}

//	i = 0;
//	while (i != fdf->grid_mh * fdf->grid_mw)
//	{
//		mlx_pixel_put(fdf->mlx, fdf->win, fdf->dot[i].x + 300, fdf->dot[i].y + 300, 0xffff);
//		printf("x: %d, y: %d\n", fdf->dot[i].x, fdf->dot[i].y);
	//	printf("x: %d, y: %d\n", xxx[i], yyy[i]);
//		i++;
//	}

}

void	z_set(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i != fdf->grid_mh * fdf->grid_mw)
	{
		if (i % 2 == 0)
			Z(i) = 30;
		i++;
	}
}

void	heigth_set(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i != fdf->grid_mh * fdf->grid_mw)
	{
		Y(i) = Y(i) - Z(i);
		i++;
	}
}

void	draw_grid(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i != fdf->grid_mh * fdf->grid_mw)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, X(i), Y(i), 0xffff);
		i++;
	}
	
	i = 0;
	while (i != fdf->grid_mh * fdf->grid_mw - fdf->grid_mw)
	{
		ft_draw_vector(fdf->dot[i], fdf->dot[i + fdf->grid_mw], fdf->mlx, fdf->win);
//		if (i % fdf->grid_mh == 0)
//			ft_draw_vector(fdf->dot[i], fdf->dot[i + fdf->grid_mw - 1], fdf->mlx, fdf->win);
		i++;
	}
	i = 0;
	while (i != fdf->grid_mh * fdf->grid_mw)
	{
	//	if (!(i % fdf->grid_mw))
		ft_draw_vector(fdf->dot[i], fdf->dot[i + 1], fdf->mlx, fdf->win);
		if ((++i + 1) % (fdf->grid_mh) == 0)
			i++;
	//	else
	//		i++;
	}
	
}


void	rotate_x(t_fdf *fdf)
{
	int		i;
	int		y;
	int		z;
	int		y1;
	int		z1;

	i = 0;
	while (i != fdf->grid_mh * fdf->grid_mw)
	{
		y = Y(i) - 500;
		z = Z(i);
		y1 = y;
		z1 = z;
		y = y1 * cos(RAD(fdf->angle)) + z1 * sin(RAD(fdf->angle));
		z = -y1 * sin(RAD(fdf->angle)) + z1 * cos(RAD(fdf->angle));
		Y(i) = y + 500;
		Z(i) = z;
		i++;
	}
}

void	rotate_y(t_fdf *fdf)
{
	int		i;
	int		x;
	int		z;
	int		x1;
	int		z1;

	i = 0;
	while (i != fdf->grid_mh * fdf->grid_mw)
	{
		x = X(i) - 500;
		z = Z(i);
		x1 = x;
		z1 = z;
		x = x1 * cos(RAD(fdf->angle)) + z1 * sin(RAD(fdf->angle));
		z = -x1 * sin(RAD(fdf->angle)) + z1 * cos(RAD(fdf->angle));
		X(i) = x + 500;
		Z(i) = z;
		i++;
	}
}


void	rotate_z(t_fdf *fdf)
{
//	double	rot_len;
	int		i;
//	int		angle;
	int		x;
	int		y;
	int		x1;
	int		y1;

	i = 0;
//	angle = fdf->angle;
	while (i != fdf->grid_mh * fdf->grid_mw)
	{
	//	rot_len = sqrt(pow(ABS((X(i) - fdf->win_w / 2)), 2) +
	//				pow(ABS((Y(i) - fdf->win_h / 2)), 2));
		x = X(i) - 500;
		y = Y(i) - 500;
		x1 = x;
		y1 = y;
		x = x1 * cos(RAD(fdf->angle)) - y1 * sin(RAD(fdf->angle));
		y = x1 * sin(RAD(fdf->angle)) + y1 * cos(RAD(fdf->angle));
		X(i) = x + 500;
		Y(i) = y + 500;
	//	printf("rot_len: %f\n", rot_len);
		i++;
	}
//	printf("aco1: %f\n", DEG(acos(cos(1))));
//	printf("acos30: %f\n", DEG(acos(cos(RAD(45)))));
//	printf("cos30: %f\n", cos(RAD(45)));
}

int		main(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win_h = 1000;
	fdf->win_w = 1000;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_w, fdf->win_h, "window");

//	fdf->dot = malloc(sizeof(t_dot) * 10);

//	fdf->dot[0].x = 0;
//	fdf->dot[0].y = 0;
//	fdf->dot[1].x = 458;
//	fdf->dot[1].y = 458;
//	fdf->dot[2].x = 100;
//	fdf->dot[2].y = 900;
//	ft_draw_vector(fdf->dot[0], fdf->dot[1], fdf->mlx, fdf->win);
//	ft_draw_vector(fdf->dot[1], fdf->dot[2], fdf->mlx, fdf->win);

	fdf->angle = 0;
	fdf->grid_mh = 20;
	fdf->grid_mw = 10;
	fdf->dot = (t_dot *)malloc(sizeof(t_dot) * (fdf->grid_mh * fdf->grid_mw));
	fdf->grid_h = 50;
	fdf->grid_w = 50;

	z_set(fdf);
	make_grid(fdf);
	rotate_z(fdf);
	heigth_set(fdf);
	draw_grid(fdf);
	fdf->output = mlx_xpm_file_to_image(fdf->mlx, "open.xpm", &fdf->dot[1].x, &fdf->dot[1].y);
//	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->output, 500, 500);	
//	mlx_clear_window(fdf->mlx, fdf->win);
	mlx_key_hook(fdf->win, key_hook_exit, fdf);
	mlx_key_hook(fdf->win, key_hook_test, fdf);
	mlx_loop(fdf->mlx);
	return(0);
}

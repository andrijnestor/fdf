/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:22:11 by anestor           #+#    #+#             */
/*   Updated: 2018/01/14 21:12:50 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_and_position(t_fdf *fdf);

int		key_hook_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == 123)
	{
		//while (keycode == 123)
		fdf->y_angle = fdf->y_angle - 15;
		mlx_clear_window(fdf->mlx, fdf->win);
	//	make_grid(fdf);
		scale_and_position(fdf);
		rotate_x(fdf);
		rotate_y(fdf);
		rotate_z(fdf);
		draw_grid(fdf);
	}
	if (keycode == 124)
	{
		fdf->y_angle = fdf->y_angle + 15;
		mlx_clear_window(fdf->mlx, fdf->win);
	//	make_grid(fdf);
		scale_and_position(fdf);
		rotate_x(fdf);
		rotate_y(fdf);
		rotate_z(fdf);
		draw_grid(fdf);
	}
	if (keycode == 126)
	{
	//	fdf->grid_h++;
		fdf->x_angle = fdf->x_angle + 15;
		mlx_clear_window(fdf->mlx, fdf->win);
	//	make_grid(fdf);
		scale_and_position(fdf);
		rotate_x(fdf);
		rotate_y(fdf);
		rotate_z(fdf);
		draw_grid(fdf);
	}
	if (keycode == 125)
	{
	//	fdf->grid_h--;
		fdf->x_angle = fdf->x_angle - 15;
		mlx_clear_window(fdf->mlx, fdf->win);
	//	make_grid(fdf);
		scale_and_position(fdf);
		rotate_x(fdf);
		rotate_y(fdf);
		rotate_z(fdf);
		draw_grid(fdf);
	}
	if (keycode == 12)
	{
		fdf->z_angle = fdf->z_angle + 15;
		mlx_clear_window(fdf->mlx, fdf->win);
	//	make_grid(fdf);
		scale_and_position(fdf);
		rotate_x(fdf);
		rotate_y(fdf);
		rotate_z(fdf);
		draw_grid(fdf);
	}
	if (keycode == 13)
	{
		fdf->z_angle = fdf->z_angle - 15;
		mlx_clear_window(fdf->mlx, fdf->win);
	//	make_grid(fdf);
		scale_and_position(fdf);
		rotate_x(fdf);
		rotate_y(fdf);
		rotate_z(fdf);
		draw_grid(fdf);
	}
	if (keycode == 69)
	{
		fdf->scale += 0.1;
		mlx_clear_window(fdf->mlx, fdf->win);
	//	make_grid(fdf);
		scale_and_position(fdf);
		rotate_x(fdf);
		rotate_y(fdf);
		rotate_z(fdf);
		draw_grid(fdf);
	}
	if (keycode == 78)
	{
		fdf->scale -= 0.1;
		mlx_clear_window(fdf->mlx, fdf->win);
	//	make_grid(fdf);
		scale_and_position(fdf);
		rotate_x(fdf);
		rotate_y(fdf);
		rotate_z(fdf);
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
	int		i;
//	int		step;
//	int		x_offset;
//	int		y_offset;

	y = 0;
	i = 0;
//	step = WIN_H / (GREATER(fdf->grid_p_h, fdf->grid_p_w)); // rewritre or not?
	/*
	if (fdf->grid_p_w >= fdf->grid_p_h)
	{
		x_offset = step / 2;
		y_offset = step / 2 + step * (fdf->grid_p_w - fdf->grid_p_h) / 2;
	}
	else
	{
		x_offset = step / 2 + step * (fdf->grid_p_h - fdf->grid_p_w) / 2;
		y_offset = step / 2;
	}
	*/
	while (y != fdf->grid_p_h)
	{
		x = 0;
		while (x != fdf->grid_p_w)
		{
		//	X(i) = step * x;
		//	Y(i) = step * y;
	//		Z(i) = step * Z(i);
			X(i) = x;
			Y(i) = y;
			x++;
			i++;
		}
		y++;
	}
	ft_memcpy(fdf->p_dot, fdf->dot, sizeof(t_dot) * fdf->grid_p_h * fdf->grid_p_w);
}

void	scale_and_position(t_fdf *fdf)
{
	int		x_offset;
	int		y_offset;
	int		i;
	int		step;

	i = 0;
	step = WIN_H / (GREATER(fdf->grid_p_h, fdf->grid_p_w));
   	step = fdf->scale * step;
	x_offset = WIN_W / 2 - fdf->grid_p_w * step / 2 + step / 2;
	y_offset = WIN_H / 2 - fdf->grid_p_h * step / 2 + step / 2;;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		PX(i) = step * X(i) + x_offset;
		PY(i) = step * Y(i) + y_offset;
		PZ(i) = step * Z(i);
		i++;
	}
}
/*
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
		yy = (fdf->grid_h / 2) * y;
		xx = fdf->win_w / 2 - (fdf->grid_w / 2 * y);
		x = 0;
		while (x != fdf->grid_p_w)
		{
			X(i) = xx + (x * (fdf->grid_w / 2));
			yy += fdf->grid_h / 2;
			Y(i) = yy;
			Z(i) = Z(i) * 100;
			x++;
			i++;
		}
		y++;
	}
	ft_memcpy(fdf->p_dot, fdf->dot, sizeof(t_dot) * fdf->grid_p_h * fdf->grid_p_w);

	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->dot[i].x, fdf->dot[i].y, COLOR(i));
//		printf("x: %d, y: %d\n", fdf->dot[i].x, fdf->dot[i].y);
	//	printf("x: %d, y: %d\n", xxx[i], yyy[i]);
		i++;
	}

}
*/
void	draw_grid(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, PX(i), PY(i), PCOLOR(i));
		i++;
	}
	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w - fdf->grid_p_w)
	{
		ft_draw_vector(fdf->p_dot[i], fdf->p_dot[i + fdf->grid_p_w], fdf->mlx, fdf->win);
		i++;
	}
	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		if (((i + 1) % fdf->grid_p_w))
			ft_draw_vector(fdf->p_dot[i], fdf->p_dot[i + 1], fdf->mlx, fdf->win);
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
		fdf->scale = 1;
		make_grid(fdf);
		scale_and_position(fdf);
	//	heigth_set(fdf);
		draw_grid(fdf);
		mlx_hook(fdf->win, 2, 5, key_hook_rotate, fdf);
		mlx_loop(fdf->mlx);
	}
	return(0);
}

int		fdf_exit(char *text)
{
	write(1, text, ft_strlen(text));
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:50:13 by anestor           #+#    #+#             */
/*   Updated: 2018/01/15 20:52:42 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hooks(int keycode, t_fdf *fdf)
{
	if (keycode == 123)
		fdf->y_angle -= ANGLE_STEP;
	if (keycode == 124)
		fdf->y_angle += ANGLE_STEP;
	if (keycode == 126)
		fdf->x_angle += ANGLE_STEP;
	if (keycode == 125)
		fdf->x_angle -= ANGLE_STEP;
	if (keycode == 12)
		fdf->z_angle += ANGLE_STEP;
	if (keycode == 13)
		fdf->z_angle -= ANGLE_STEP;
	if (keycode == 69)
		fdf->scale += SCALE_STEP;
	if (keycode == 78)
		fdf->scale -= SCALE_STEP;
	if (keycode == 19)
		fdf->z_scale += SCALE_STEP;
	if (keycode == 18)
		fdf->z_scale -= SCALE_STEP;
	if (keycode == 53)
		exit(0);
	mlx_clear_window(fdf->mlx, fdf->win);
	render(fdf);
	return (0);
}

int		hook_mouse_down(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	fdf->mouse.is_down = button;
	return (0);
}

int		hook_mouse_up(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	(void)button;
	fdf->mouse.is_down = 0;
	return (0);
}

int		hook_mouse_move(int x, int y, t_fdf *fdf)
{
	fdf->mouse.last_x = fdf->mouse.x;
	fdf->mouse.last_y = fdf->mouse.y;
	fdf->mouse.x = x;
	fdf->mouse.y = y;
	if (fdf->mouse.is_down == 1)
	{
		fdf->x_angle -= (fdf->mouse.last_y - y) / 2;
		fdf->y_angle -= (fdf->mouse.last_x - x) / 2;
	}
	else if (fdf->mouse.is_down == 2)
	{
		fdf->x_angle -= (fdf->mouse.last_y - y) / 2;
		fdf->z_angle += (fdf->mouse.last_x - x) / 2;
	}
	if (fdf->mouse.is_down)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		render(fdf);
	}
	return (0);
}

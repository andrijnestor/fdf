/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:50:13 by anestor           #+#    #+#             */
/*   Updated: 2018/01/15 18:36:51 by anestor          ###   ########.fr       */
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

	printf("%d\n", keycode); //debugging
	return (0);
}

/*
int        hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
    (void)x;
    if (y < 0)
        return (0);
    mlx->mouse->isdown |= 1 << button;
    return (0);
}

int        hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
    (void)x;
    (void)y;
    mlx->mouse->isdown &= ~(1 << button);
    return (0);
}

int        hook_mousemove(int x, int y, t_mlx *mlx)
{
    mlx->mouse->lastx = mlx->mouse->x;
    mlx->mouse->lasty = mlx->mouse->y;
    mlx->mouse->x = x;
    mlx->mouse->y = y;
 	if (mlx->mouse->isdown & (1 << 1) && mlx->mouse->isdown & (1 << 2))
    {
        mlx->cam->offsetx += (x - mlx->mouse->lastx);
        mlx->cam->offsety += (y - mlx->mouse->lasty);
    }
    else if (mlx->mouse->isdown & (1 << 1))
    {
        mlx->cam->x += (mlx->mouse->lasty - y) / 200.0f;
        mlx->cam->y -= (mlx->mouse->lastx - x) / 200.0f;
    }
    else if (mlx->mouse->isdown & (1 << 2))
    {
        mlx->cam->scale += (mlx->mouse->lasty - y) / 10.0f + 0.5f;
        if (mlx->cam->scale < 1)
            mlx->cam->scale = 1;
    }
    if (mlx->mouse->isdown)
        render(mlx);
    return (0);
}*/


#include "fdf.h"
#include <time.h>

int		key_hook_exit(int keycode, t_fdf *fdf)
{
	if (keycode == 3)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		ft_draw_vector(fdf->dot[0], fdf->dot[2], fdf->mlx, fdf->win);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->output, 300, 300);	
	}
	printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
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
	i = 0;
	while (i != fdf->grid_mh * fdf->grid_mw)
	{
//		mlx_pixel_put(fdf->mlx, fdf->win, fdf->dot[i].x + 300, fdf->dot[i].y + 300, 0xffff);
		printf("x: %d, y: %d\n", fdf->dot[i].x, fdf->dot[i].y);
	//	printf("x: %d, y: %d\n", xxx[i], yyy[i]);
		i++;
	}

}

void	draw_grid(t_fdf *fdf)
{
	int		i;

	i = 0;
	while(i != fdf->grid_mh * fdf->grid_mw)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, X(i), Y(i), 0xffff);
		i++;
	}
}

void	rotate(t_fdf *fdf)
{
	double	rot_len;
	int		i;

	i = 0;
	while (i != fdf->grid_mh * fdf->grid_mw)
	{
		rot_len = sqrt(pow(ABS((X(i) - fdf->win_w / 2)), 2) +
					pow(ABS((Y(i) - fdf->win_h / 2)), 2));
	//	X(i) = cos(RAD(45)) * rot_len;
//		Y(i) = Y(i) + 5;	
	//	Y(i) = Y(i) - sin(RAD(30));;
	//	X(i) = X(i) * 1.488;
	//	Y(i) = Y(i) * 0.07;
		double percent;
		percent = (GREATER(((double)500 - X(i)), ((double)500 - Y(i)))) +
					(LOWER(((double)500 - X(i)), ((double)500 - Y(i))));
	//	percent = (GREATER(X(i), Y(i))) +
	//				(LOWER(X(i), Y(i)));
//		printf("per: %f\n", percent);
	//	printf("lol: %f\n", (((double)500 - (Y(i))) / percent));
		printf("asi: %f\n", DEG(asin((((double)500 - Y(i)) / percent))));
		printf("aco: %f\n", DEG(acos((((double)500 - Y(i)) / percent))));
	//	if ((double)975 - X(i) > (double)975 - Y(i))

//			printf("aco: %f\n", DEG(acos((X(i) / (((double)975 - X(i)) / 100)) / 100)));
	//	else
//			printf("asi: %f\n", DEG(asin((Y(i) / (((double)975 - Y(i)) / 100)) / 100)));

		printf("rot_len: %f\n", rot_len);
		i++;
	}
	printf("aco1: %f\n", DEG(acos(cos(1))));
	printf("acos30: %f\n", DEG(acos(cos(RAD(45)))));
	printf("cos30: %f\n", cos(RAD(45)));
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


	fdf->grid_mh = 20;
	fdf->grid_mw = 20;
	fdf->dot = (t_dot *)malloc(sizeof(t_dot) * (fdf->grid_mh * fdf->grid_mw));
	fdf->grid_h = 50;
	fdf->grid_w = 50;

	make_grid(fdf);
	rotate(fdf);
	draw_grid(fdf);
	fdf->output = mlx_xpm_file_to_image(fdf->mlx, "open.xpm", &fdf->dot[1].x, &fdf->dot[1].y);
//	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->output, 500, 500);	
//	mlx_clear_window(fdf->mlx, fdf->win);
	mlx_key_hook(fdf->win, key_hook_exit, fdf);
	mlx_loop(fdf->mlx);
	return(0);
}

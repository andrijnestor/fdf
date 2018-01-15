/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:22:11 by anestor           #+#    #+#             */
/*   Updated: 2018/01/15 22:08:10 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2 || argc == 4)
	{
		if ((fdf = ft_memalloc(sizeof(t_fdf))) == NULL)
			fdf_exit("Out of memory\n");
		if (argc == 4)
			color_gamma(ft_atoi_base(argv[2], 16),
					ft_atoi_base(argv[3], 16), fdf);
		read_fdf(argv[1], fdf);
		if ((fdf->mlx = mlx_init()) == NULL)
			fdf_exit("Mlx error\n");
		if ((fdf->win = mlx_new_window(fdf->mlx, fdf->win_w,
							fdf->win_h, "fdf")) == NULL)
			fdf_exit("Mlx error\n");
		make_grid(fdf);
		first_scale(fdf);
		render(fdf);
		mlx_hook(fdf->win, 2, 5, key_hooks, fdf);
		mlx_hook(fdf->win, 4, 0, hook_mouse_down, fdf);
		mlx_hook(fdf->win, 5, 0, hook_mouse_up, fdf);
		mlx_hook(fdf->win, 6, 0, hook_mouse_move, fdf);
		mlx_loop(fdf->mlx);
	}
	return (0);
}

int		fdf_exit(char *text)
{
	write(1, text, ft_strlen(text));
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:22:11 by anestor           #+#    #+#             */
/*   Updated: 2018/01/15 18:36:48 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		first_scale(fdf);
		render(fdf);
		mlx_hook(fdf->win, 2, 5, key_hooks, fdf);
		mlx_loop(fdf->mlx);
	}
	return (0);
}

int		fdf_exit(char *text)
{
	write(1, text, ft_strlen(text));
	exit(1);
}

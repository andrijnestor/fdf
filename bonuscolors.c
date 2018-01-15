/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuscolors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:59:13 by anestor           #+#    #+#             */
/*   Updated: 2018/01/15 22:06:08 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_gamma(int c1, int c2, t_fdf *fdf)
{
	fdf->col_param.is_set = 1;
	fdf->col_param.col1 = c1;
	fdf->col_param.col2 = c2;
}

void	change_colors(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		if (Z(i) == 0)
			COLOR(i) = fdf->col_param.col1;
		else
			COLOR(i) = fdf->col_param.col2;
		i++;
	}
}

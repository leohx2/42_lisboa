/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:07:59 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/29 15:21:41 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

int	ray_maker(t_vars *vars, double	ray_angle)
{
	double	endX;
	double	endY;

	endX = cos(ray_angle) * 30;
	endY = sin(ray_angle) * 30;
	player_view(vars, 0x6600cc, endX, endY);
	return (0);
}

int	cast_all_rays(t_vars *vars, t_aux *mapa)
{
	int		column_id;
	double	ray_angle;
	int		index;

	index = 0;
	ray_angle = vars->pa - (F_ANGLE / 2);
	column_id = 0;	
	while (index < vars->num_rays)
	{
		ray_maker(vars, ray_angle);
		ray_angle += F_ANGLE / vars->num_rays;
		column_id++;
		index++;
	}
	
	return (0);
}
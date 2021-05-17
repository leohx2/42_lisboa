/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 10:26:34 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/05 10:09:14 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

int verify_colision(t_vars *vars, t_aux *mapa)
{
	double	movestep;
	double	y;
	double	x;
	
	y = vars->py;
	x = vars->px;
	movestep = vars->direction * vars->movespeed;
	x += cos(vars->pa) * movestep;
	y += sin(vars->pa) * movestep;
	if(mapa->colision[(int)y/BLOCK_S][(int)x/BLOCK_S] == 1)
		return(1);
	vars->px = x;
	vars->py = y;
	return (0);
}

int verify_intercept(t_aux *map, int x, int y, t_rays *rays, t_vars *vars)
{
	
	if (map->colision[y / BLOCK_S][x / BLOCK_S] == 1)
		return (1);
	else
		return (0);
}

int verify_pa(double *angle)
{
	if (*angle >= (2 * M_PI))
		*angle -= (2 * M_PI);
	if (*angle < 0)
		*angle += (2 * M_PI);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 10:26:34 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/29 13:55:23 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

int verify_colision(t_vars *vars, t_aux *mapa)
{
	if(mapa->colision[(int)vars->py/64][(int)vars->px/64] == 1)//64 is the block size
		return(1);
	else
		return(0);
}
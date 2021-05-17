/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:37:50 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/09 00:52:06 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS
# define RAYS
# include "cub3.h"

int		cast_all_rays(t_vars *vars, t_aux *mapa, t_rays *rays);
int		horizontal_step(t_vars *vars, t_rays *rays);
int		vertical_step(t_vars *vars, t_rays *rays);
void	horizontal_intercept(t_vars *vars, t_rays *rays);
void	vertical_intercept(t_vars *vars, t_rays *rays);
int		ray_size(t_vars *vars, t_rays *rays);
void	check_direction(t_rays *rays);
int 	verify_intercept(t_aux *map, int x, int y, t_rays *rays, t_vars *vars);
void	cal_distance(t_rays *rays, t_vars *vars);
void	walls_pj(t_rays *rays, t_vars *vars, t_aux *mapa, int startX);
void	draw_rect(t_rays *rays, t_vars *vars, int colum_id);
void wall_project(t_vars *vars, int color, double startX, double startY, double endX, double endY, t_aux *mapa);
#endif

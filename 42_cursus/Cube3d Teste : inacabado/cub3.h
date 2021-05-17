/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 08:27:54 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/09 01:02:32 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cube3h
# define Cube3h
# include "minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# define MINI_MAP 0.2
# define F_ANGLE	(60 * (M_PI / 180))
# define MAX_HEIGHT 512
# define MAX_WIDTH 1024
# define BLOCK_S 64
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53

typedef struct s_rays
{
	double	xintercept;
	double	yintercept;
	double	hwallhitx;
	double	hwallhity;
	double	vwallhitx;
	double	vwallhity;
	double	xstep;
	double	ystep;
	double	r_wallhitx;// r_ = "real" one
	double	r_wallhity;// r_ = "real" one
	double	distance;
	double	ray_angle;
	int		l_left; // l == looking
	int		l_right;
	int		l_down;
	int		l_up;
	int		isv_wall;
	int		ish_wall;
	int		wasverticalhit;
	double	wall_proj_height;
	double	distance_proj_plane;
} t_rays;

typedef struct s_aux
{
	int		height;
	int		width;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		*buffer;
	int		colision[1024][1024];//teste!
	void	*image;
} t_aux;


typedef struct s_vars
{
	double	px;
	double	py;
	double	pdx;
	double	pdy;
	double	pa;
	void	*mlx;
	void	*win;
	double	height;
	double	width;
	double 	r_heigth;
	double	r_width;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		*buffer;
	void	*image;
	int		num_rays;
	int		rays_strip;
	double	rotation_speed;
	int		movespeed;
	int		direction;
	int		turn_direction;
	t_rays	rays;
	t_aux	aux;
}	t_vars;

void	colors( t_vars *image, int color);
void	color_player( t_vars *vars, int color);
void	color_map(t_vars *vars, t_aux *map, int px, int py, int color);
void	drawmap2d(t_vars *vars, t_aux *mapa);
int		verify_colision(t_vars *vars, t_aux *mapa);
void	player_view(t_vars *vars, int color, double endX, double endY);////
void	render(t_vars *vars, int color);
int		verify_pa(double *angle);
#endif

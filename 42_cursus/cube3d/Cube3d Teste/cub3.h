/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 08:27:54 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/29 14:46:55 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "stdio.h"
#include <math.h>
#define PI 3.14159265
#define F_ANGLE	(60 * (PI / 180))
#define MAX_HEIGHT 512
#define MAX_WIDTH 1024
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define ESC 53

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
	t_aux	aux;
}	t_vars;

void	colors( t_vars *image, int color);
void	color_player( t_vars *vars, int color);
void	color_map(t_vars *vars, t_aux *map, int px, int py, int color);
void	drawmap2d(t_vars *vars, t_aux *mapa);
int		verify_colision(t_vars *vars, t_aux *mapa);
void	player_view(t_vars *vars, int color, double endX, double endY);////
void	render(t_vars *vars, int color);
int		cast_all_rays(t_vars *vars, t_aux *mapa);
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 08:54:08 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/29 15:28:13 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

void color_player( t_vars *vars, int color)
{
	vars->height = 0;
	vars->image = mlx_new_image(vars->mlx, vars->r_width, vars->r_heigth);
	vars->buffer = (int*)mlx_get_data_addr(vars->image, &vars->pixel_bits, &vars->line_bytes, &vars->endian);
	while (vars->height < vars->r_heigth)
	{
		vars->width = 0;
		while (vars->width < vars->r_width)
		{
			vars->buffer[(int)(vars->height * vars->r_width + vars->width)] = color;
			vars->width++;
		}
		vars->height++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image, vars->px, vars->py);
}

void player_view(t_vars *vars, int color, double endX, double endY)	//-------- visão do play ---------
{
	double	deltaX;
	double	deltaY;
	double	pixelX;
	double	pixelY;
	double	pixels;

	deltaX = endX;
	deltaY = endY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = vars->px + vars->r_heigth/2;
	pixelY = vars->py + vars->r_width/2;
	while (pixels > 0)
	{
		mlx_pixel_put(vars->mlx, vars->win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

void	color_map(t_vars *vars, t_aux *map, int px, int py, int color)
{
	map->height = 0;
	map->image = mlx_new_image(vars->mlx, 64, 64);
	map->buffer = (int*)mlx_get_data_addr(map->image, &map->pixel_bits, &map->line_bytes, &map->endian);
	while (map->height < 63)
	{
		map->width = 0;
		while (map->width < 63)
		{
			map->buffer[(map->height * 64 + map->width)] = color;
			map->width++;
		}
		map->height++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, map->image, px, py);
}

void	render(t_vars *vars, int color)
{
	mlx_clear_window(vars->mlx, vars->win);
	drawmap2d(vars, &vars->aux);
	cast_all_rays(vars, &vars->aux);
	color_player(vars, color);
}
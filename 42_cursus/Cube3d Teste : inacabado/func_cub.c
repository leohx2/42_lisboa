/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 08:54:08 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/09 01:26:29 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

void color_player( t_vars *vars, int color)
{
	vars->height = 0;
	vars->image = mlx_new_image(vars->mlx, MINI_MAP * vars->r_width, MINI_MAP * vars->r_heigth);
	vars->buffer = (int*)mlx_get_data_addr(vars->image, &vars->pixel_bits, &vars->line_bytes, &vars->endian);
	while (vars->height < MINI_MAP * vars->r_heigth)
	{
		vars->width = 0;
		while (vars->width < MINI_MAP * vars->r_width)
		{
			vars->buffer[(int)(vars->height * (MINI_MAP * vars->r_width) + vars->width)] = color;
			vars->width++;
		}
		vars->height++;//
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image, MINI_MAP * vars->px, MINI_MAP * vars->py);
}

void player_view(t_vars *vars, int color, double endX, double endY)	//-------- visão do play ---------
{
	double	pixelX;
	double	pixelY;
	double	pixels;

	pixels = sqrt((endX * endX) + (endY * endY));
	endX /= pixels;
	endY /= pixels;
	pixelX = vars->px;
	pixelY = vars->py;
	while (pixels > 0)
	{
		mlx_pixel_put(vars->mlx, vars->win, MINI_MAP * pixelX, MINI_MAP * pixelY, color);
		pixelX += endX;
		pixelY += endY;
		--pixels;
	}
}

void	color_map(t_vars *vars, t_aux *map, int px, int py, int color)
{
	map->height = 0;
	map->image = mlx_new_image(vars->mlx, 64, 64);
	map->buffer = (int*)mlx_get_data_addr(map->image, &map->pixel_bits, &map->line_bytes, &map->endian);
	while (map->height < MINI_MAP * (BLOCK_S - 1))
	{
		map->width = 0;
		while (map->width < MINI_MAP * (BLOCK_S - 1))
		{
			map->buffer[(map->height * BLOCK_S + map->width)] = color;
			map->width++;
		}
		map->height++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, map->image, MINI_MAP * px, MINI_MAP * py);
}

void	render(t_vars *vars, int color)
{
	printf("RENDER \n");
	mlx_clear_window(vars->mlx, vars->win);
	drawmap2d(vars, &vars->aux);
	color_player(vars, color);
	cast_all_rays(vars, &vars->aux, &vars->rays);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:22:38 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/09 01:28:03 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

void	walls_pj(t_rays *rays, t_vars *vars, t_aux *wall, int startX)
{
	double	startY;
	double	distance;
	double	endy;
	double	endx;

	distance = rays->distance * cos(rays->ray_angle - vars->pa);
	rays->distance_proj_plane = (MAX_WIDTH / 2) / tan(F_ANGLE / 2);
	rays->wall_proj_height = (BLOCK_S / distance) * rays->distance_proj_plane;
	startY = (MAX_HEIGHT / 2) - (rays->wall_proj_height / 2);
	if (startY < 0)
		startY = 0;
	endx = startX;
	endy = (MAX_HEIGHT / 2) + (rays->wall_proj_height / 2);
	if (endy >= MAX_HEIGHT)
		endy = MAX_HEIGHT - 1.0;
	wall_project(vars, 0x33FFFF, startX, startY, endx, endy, wall);
}

void wall_project(t_vars *vars, int color, double startX, double startY, double endX, double endY, t_aux *mapa)
{
	double	deltaX;
	double	deltaY;
	double	pixelX;
	double	pixelY;
	int		pixels;

	deltaX = endX - startX;
	deltaY = endY - startY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = startX;
	pixelY = startY;
	while (pixels)
	{
		//mlx_pixel_put(vars->mlx, vars->win, pixelX, pixelY, color);
		mapa->buffer[(int)pixelY * MAX_WIDTH + (int)pixelX] = color;
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

/*
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
*/
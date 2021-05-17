/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:07:59 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/09 01:24:29 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

int		ray_maker(t_vars *vars, t_rays *ray)
{
	static int test;

	ray_size(vars, ray);
	verify_pa(&ray->ray_angle);
	player_view(vars, 0x6600cc, ray->r_wallhitx, ray->r_wallhity);
	return (0);
}

int		cast_all_rays(t_vars *vars, t_aux *mapa, t_rays *rays)
{
	int		column_id;

	rays->ray_angle = vars->pa - (F_ANGLE / 2);
	column_id = 0;
	vars->aux.image = mlx_new_image(vars->mlx,	MAX_WIDTH, MAX_HEIGHT);
	vars->aux.buffer = (int*)mlx_get_data_addr(vars->aux.image, &vars->aux.pixel_bits, &vars->aux.line_bytes, &vars->aux.endian);
	while (column_id < vars->num_rays)
	{
		ray_maker(vars, &vars->rays);
		walls_pj(rays, vars, &vars->aux, column_id);
		rays->ray_angle += F_ANGLE / vars->num_rays;
		column_id++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->aux.image, 0, 0);
	return (0);
}

int		ray_size(t_vars *vars, t_rays *rays)
{
	check_direction(rays);
	horizontal_intercept(vars, rays);
	vertical_intercept(vars, rays);
	cal_distance(rays, vars);
	return (0);
}

//-------HORIZONTAL--------//
void	horizontal_intercept(t_vars *vars, t_rays *rays)//mudar pra void
{
	rays->yintercept = (floor(vars->py / BLOCK_S)) * BLOCK_S;
	if (rays->l_down)//facing down
		rays->yintercept += BLOCK_S;
	rays->xintercept = vars->px + (rays->yintercept - vars->py) / tan(rays->ray_angle);
	if (rays->l_right && (int)rays->xintercept/BLOCK_S < (int)vars->px/BLOCK_S)
		rays->xintercept = -1;
	else if (rays->l_left && (int)rays->xintercept/BLOCK_S > (int)vars->px/BLOCK_S)
		rays->xintercept = -1;
	horizontal_step(vars, rays);
}

int		horizontal_step(t_vars *vars, t_rays *rays)
{
	double	nextHorzTouchX;
	double	nextHorzTouchY;

	rays->ish_wall = 0;
	rays->ystep = BLOCK_S;
	if (!rays->l_down)
		rays->ystep *= -1;
	rays->xstep = BLOCK_S / tan(rays->ray_angle);
	if (rays->l_left && rays->xstep > 0)
		rays->xstep *= -1;
	if (!rays->l_left && rays->xstep < 0)
		rays->xstep *= -1;
	nextHorzTouchX = rays->xintercept;
	nextHorzTouchY = rays->yintercept;
	while(rays->ish_wall == 0 && nextHorzTouchX <= MAX_WIDTH && nextHorzTouchX >= 0 && nextHorzTouchY <= MAX_HEIGHT && nextHorzTouchY >= 0)
	{
		if(verify_intercept(&vars->aux, nextHorzTouchX, floor(nextHorzTouchY - rays->l_up), rays, vars))
		{
			rays->ish_wall = 1;
			rays->hwallhitx = nextHorzTouchX;
			rays->hwallhity = nextHorzTouchY;
			//player_view(vars, 0x6600cc, nextVertTouchX - vars->px, nextVertTouchY - vars->py);
		}
		else
		{
			nextHorzTouchX += rays->xstep;
			nextHorzTouchY += rays->ystep;
		}
	}
	return(0);
}

//------VERTICAL-----//
void	vertical_intercept(t_vars *vars, t_rays *rays)
{
	rays->xintercept = floor(vars->px / BLOCK_S) * BLOCK_S;
	if (rays->l_right)//facing right
		rays->xintercept += BLOCK_S;
	rays->yintercept = vars->py + ((rays->xintercept - vars->px) * tan(rays->ray_angle));
	vertical_step(vars, rays);
}

int		vertical_step(t_vars *vars, t_rays *rays)
{
	double	nextVertTouchX;
	double	nextVertTouchY;
	static int test;

	rays->isv_wall = 0;
	rays->xstep = BLOCK_S;
	if (rays->l_left)
		rays->xstep *= -1;
	rays->ystep = BLOCK_S * tan(rays->ray_angle);
	if (rays->l_up && rays->ystep > 0)
		rays->ystep *= -1;
	if (rays->l_down && rays->ystep < 0)
		rays->ystep *= -1;

	nextVertTouchX = rays->xintercept;
	nextVertTouchY = rays->yintercept;
	while(nextVertTouchX < MAX_WIDTH - 1 && nextVertTouchX>= 0 && nextVertTouchY <= MAX_HEIGHT - 1&& nextVertTouchY >= 0)
	{
		if(verify_intercept(&vars->aux, (nextVertTouchX - rays->l_left), nextVertTouchY, rays, vars))
		{
			rays->isv_wall = 1;
			rays->vwallhitx = nextVertTouchX;
			rays->vwallhity = nextVertTouchY;
			return (0);
		}
		else
		{
			nextVertTouchX += rays->xstep;
			nextVertTouchY += rays->ystep;
		}
	test++;
	}
	return (0);
}

// ---- DIRECTION ----//
void	check_direction(t_rays *rays)
{
	if (rays->ray_angle > M_PI_2 && rays->ray_angle < (3 * M_PI_2))
	{
		rays->l_left = 1;
		rays->l_right = 0;
	}
	else
	{
		rays->l_right = 1;
		rays->l_left = 0;
	}
	if (rays->ray_angle > 0 && rays->ray_angle < M_PI)
	{
		rays->l_down = 1;
		rays->l_up = 0;
	}
	else
	{
		rays->l_up = 1;
		rays->l_down = 0;
	}
}

// --- DISTANCE --- //
void	cal_distance(t_rays *rays, t_vars *vars)
{
	double	v_1;
	double	v_2;

	//printf("-----\nHOR %d %d\tVER %d %d\n------\n", (int)rays->hwallhitx/64, (int)rays->hwallhity/64, (int)rays->vwallhitx/64, (int)rays->vwallhity/64);
	if (rays->ish_wall == 1)
		v_1 = sqrt((rays->hwallhitx - vars->px) * (rays->hwallhitx - vars->px) +
			(rays->hwallhity - vars->py) * (rays->hwallhity - vars->py));
	else
		v_1 = __INT_MAX__;
	if (rays->isv_wall == 1)
		v_2 = sqrt((rays->vwallhitx - vars->px) * (rays->vwallhitx - vars->px) +
			(rays->vwallhity - vars->py) * (rays->vwallhity - vars->py));
	else
		v_2 = __INT_MAX__;
	if (v_1 < v_2)
	{
		rays->r_wallhitx = rays->hwallhitx - vars->px;
		rays->r_wallhity = rays->hwallhity - vars->py;
		rays->distance = v_1;
		rays->wasverticalhit = 0;
	}
	else
	{
		rays->r_wallhitx = rays->vwallhitx - vars->px;
		rays->r_wallhity = rays->vwallhity - vars->py;
		rays->distance = v_2;
		rays->wasverticalhit = 1;
	}
}

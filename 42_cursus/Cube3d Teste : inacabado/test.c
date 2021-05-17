/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:32:28 by lrosendo          #+#    #+#             */
/*   Updated: 2021/05/09 01:25:43 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

int mapX = 8, mapY = 8, mapS = BLOCK_S;
int map[] =
{
1,1,1,1,1,1,1,1,
1,0,1,0,0,0,0,1,
1,0,1,0,0,0,0,1,
1,0,1,0,0,0,0,1,
1,0,0,0,0,0,0,1,
1,0,0,0,0,1,0,1,
1,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,
};

int key_print(int keycode, t_vars *vars)
{
	int color = 0xFFFF00;
	double	movestep;

	if (keycode == UP)
		vars->direction = 1;
	else if (keycode == DOWN)
		vars->direction = -1;
	else if (keycode == RIGHT)
		vars->turn_direction = 1;
	else if (keycode == LEFT)
		vars->turn_direction = -1;
	vars->pa += vars->turn_direction * vars->rotation_speed;
	verify_pa(&vars->pa);
	verify_colision(vars, &vars->aux);
	render(vars, color);
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == UP)
		vars->direction = 0;
	else if (keycode == DOWN)
		vars->direction = 0;
	else if (keycode == RIGHT)
		vars->turn_direction = 0;
	else if (keycode == LEFT)
		vars->turn_direction = 0;
	return (0);
}

void drawmap2d(t_vars *vars, t_aux *mapa)
{
	int color;
	int x,y,xo,yo;

	mapa->colision[0][0] = 0;
	y = 0;
	while (y < mapY)
	{
		x = 0;
		mapa->colision[y][x] = 0;
		while (x < mapX)
		{
			if (map[y * mapX + x] == 1)
			{
				mapa->colision[y][x] = 1;
				color = 0x33FFFF;
			}
			else
				color = 0xA0A0A0;
			xo = x * mapS;
			yo = y * mapS;
			color_map(vars, &vars->aux, xo, yo, color);
			x++;
		}
		y++;
	}
	vars->num_rays = (x - 1) * BLOCK_S;
}

void	creat_init(t_vars *vars)
{
	printf("INICIO\n");
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, MAX_WIDTH, MAX_HEIGHT, "testando");
	vars->direction = 0;
	vars->turn_direction = 0;
	vars->pa = M_PI / 2;
	vars->px = 300;
	vars->py = 200;
	vars->movespeed = 5;
	vars->rotation_speed = 5 * (M_PI / 180);
	vars->r_width = 8;
	vars->r_heigth = 8;
	drawmap2d(vars, &vars->aux);
	color_player(vars, 0xFFFF00);
}

int main()
{
	t_vars	vars;

	int		color = 0xA0A0A0;
	creat_init(&vars);
	mlx_hook(vars.win, 2, 1L<<0, key_print, &vars);
	mlx_hook(vars.win, 3, 1L<<1, key_release, &vars);
	mlx_loop(vars.mlx);
}

/*
int key_print(int keycode, t_vars *vars)
{
	int color = 0xFFFF00;

	if (keycode == LEFT)
	{
		vars->pa -= vars->rotation_speed;
		if (vars->pa < 0)
			vars->pa += 2 * M_PI;
		vars->pdx = cos(vars->pa) * 5;
		vars->pdy = sin(vars->pa) * 5;
	}
	else if (keycode == RIGHT)
	{
		vars->pa += vars->rotation_speed;
		if (vars->pa >= (2 * M_PI))
			vars->pa -= 2 * M_PI;
		vars->pdx = cos(vars->pa) * 5;
		vars->pdy = sin(vars->pa) * 5;
	}
	else if (keycode == UP)
	{
		vars->px += vars->pdx;
		vars->py += vars->pdy;
		if (verify_colision(vars, &vars->aux))
		{
			vars->px -= vars->pdx;
			vars->py -= vars->pdy;
		}
	}
	else if (keycode == DOWN)
	{
		vars->px -= vars->pdx;
		vars->py -= vars->pdy;
		if (verify_colision(vars, &vars->aux))
		{
			vars->px += vars->pdx;
			vars->py += vars->pdy;
		}	
	}
	//printf("\n------------------\nY -> %d\tx -> %d\n------------------\n", (int)vars->py/64, (int)vars->px/64);
	render(vars, color);
	return (0);
}*/
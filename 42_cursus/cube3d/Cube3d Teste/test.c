/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:32:28 by lrosendo          #+#    #+#             */
/*   Updated: 2021/04/29 15:27:52 by lrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

int mapX = 8, mapY = 8, mapS = 64;
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

	if (keycode == LEFT)
	{
		vars->pa -= 0.1;
		if (vars->pa < 0)
			vars->pa += 2 * PI;
		vars->pdx = cos(vars->pa) * 5;
		vars->pdy = sin(vars->pa) * 5;
	}
	else if (keycode == RIGHT)
	{
		vars->pa += 0.1;
		if (vars->pa > (2 * PI))
			vars->pa -= 2 * PI;
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
}

void drawmap2d(t_vars *vars, t_aux *mapa)
{
	int color;
	int x,y,xo,yo;

	mapa->colision[0][0] = 0;
	y = 0;
	while (y <= mapY)
	{
		x = 0;
		mapa->colision[y][x] = 0;
		while (x < mapX)
		{
			if (map[y * mapX + x] == 1)
			{
				mapa->colision[y][x] = 1;
				color = 0xFFFFFF;
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
	vars->num_rays = x * 64;
}

void	creat_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, MAX_WIDTH, MAX_HEIGHT, "testando");
	vars->pa = PI;
	vars->pdx = cos(vars->pa) * 5;
	vars->pdy = sin(vars->pa) * 5;
	vars->px = 300;
	vars->py = 200;
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
	mlx_loop(vars.mlx);
}
/*
int key_print(int keycode, t_vars *vars)
{
	int color = 0xFFFFFF;

	vars->r_width = 5;
	vars->r_heigth = 5;
	if (keycode == LEFT && MAX_WIDTH - vars->px > 64)
	{
		vars->px -= 10;
	}
	else if (keycode == RIGHT)
	{
		vars->px += 10;
	}
	else if (keycode == UP)
	{
		vars->py -= 10;
	}
	else if (keycode == DOWN)
	{
		vars->py += 10;
	}
	//mlx_clear_window(vars->mlx, vars->win);/
	color_player(vars, color, vars->px, vars->py);
	return (0);
}

int mapX = 8, mapY = 8, mapS = 64;
int map[] =
{
1,1,1,1,1,1,1,1,
1,0,1,0,0,0,0,1,
1,0,1,0,0,0,0,1,
1,0,1,0,0,0,0,1,
1,0,1,0,0,0,0,1,
1,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,
};

void drawmap2d(t_vars *vars, t_vars *mapa)
{
	int color;
	int x,y,xo,yo;
	y = 0;
	while (y <= mapY)
	{
		x = 0;
		while (x < mapX)
		{
			if (map[y * mapX + x] == 1)
				color = 0xFFFFAF;
			else
				color = 0xA0A0A0;
			xo = x * mapS;
			yo = y * mapS;
			color_map(vars, mapa, xo, yo, color);
			x++;
		}
		y++;
	}
}

void	creat_win(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, MAX_WIDTH, MAX_HEIGHT, "testando");
}

int main()
{
	t_vars	mapa;
	t_vars	vars;
	int		color = 0xA0A0A0;

	vars.px = 300;
	vars.py = 250;
	creat_win(&vars);
	drawmap2d(&vars, &mapa);
	mlx_hook(vars.win, 2, 1L<<0, key_print, &vars);
	mlx_loop(vars.mlx);

}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:32:10 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/12 15:20:39 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sprite_matrix(t_game *game, t_parse *data, int i)
{
	game->rc.sprite.x = game->sprite[game->spriteorder[i]]->x - data->player.x;
	game->rc.sprite.y = game->sprite[game->spriteorder[i]]->y - data->player.y;
	game->rc.invdet = 1.0 / (game->rc.plane.x * game->rc.dir.y - game->rc.dir.x
	* game->rc.plane.y);
	game->rc.transform.x = game->rc.invdet * (game->rc.dir.y * game->rc.sprite.x
	- game->rc.dir.x * game->rc.sprite.y);
	game->rc.transform.y = game->rc.invdet * (-game->rc.plane.y *
	game->rc.sprite.x + game->rc.plane.x * game->rc.sprite.y);
	game->rc.spritesx = (int)game->rc.pre2 * (1 + game->rc.transform.x /
	game->rc.transform.y);
}

void	sort_sprite(t_parse *data, t_game *game)
{
	int		x;
	int		tmp;
	int		tmporder;

	x = 0;
	while (x < (data->nbsprite - 1))
	{
		if (game->sprite[x]->spritedis > game->sprite[x + 1]->spritedis)
		{
			tmp = game->sprite[x]->spritedis;
			tmporder = game->spriteorder[x];
			game->sprite[x]->spritedis = game->sprite[x + 1]->spritedis;
			game->spriteorder[x] = game->spriteorder[x + 1];
			game->sprite[x + 1]->spritedis = tmp;
			game->spriteorder[x + 1] = tmporder;
			x = 0;
		}
		else
			x++;
	}
}

void	calcul_sprite_xy(t_game *game, t_parse *data, int *stripe)
{
	game->rc.spritesize.y = abs((int)(data->resy / game->rc.transform.y));
	game->rc.dstart_s.y = -game->rc.spritesize.y / 2 + game->rc.pre3;
	if (game->rc.dstart_s.y < 0)
		game->rc.dstart_s.y = 0;
	game->rc.dend_s.y = game->rc.spritesize.y / 2 + game->rc.pre3;
	if (game->rc.dend_s.y >= data->resy)
		game->rc.dend_s.y = game->rc.pre4;
	game->rc.spritesize.x = abs((int)(data->resy / game->rc.transform.y));
	game->rc.dstart_s.x = -game->rc.spritesize.x / 2 + game->rc.spritesx;
	if (game->rc.dstart_s.x < 0)
		game->rc.dstart_s.x = 0;
	game->rc.dend_s.x = game->rc.spritesize.x / 2 + game->rc.spritesx;
	if (game->rc.dend_s.x >= data->resx)
		game->rc.dend_s.x = game->rc.pre5;
	*stripe = game->rc.dstart_s.x;
}

void	write_sprite(t_game *game, t_parse *data, int i, int *stripe)
{
	int		y;

	while (*stripe < game->rc.dend_s.x)
	{
		game->rc.tex.x = (int)((256 * (*stripe - (-game->rc.spritesize.x / 2 +
		game->rc.spritesx)) * game->sprite[game->spriteorder[i]]
		->sprite[game->sprite[game->spriteorder[i]]->xpm]->width /
		game->rc.spritesize.x) / 256);
		if (game->rc.transform.y > 0 && *stripe > 0 && *stripe < data->resx &&
		game->rc.transform.y < game->rc.zbuffer[*stripe])
		{
			y = game->rc.dstart_s.y;
			while (y < game->rc.dend_s.y)
			{
				game->rc.d = y * 256 - game->rc.pre1 + game->rc.pre6;
				game->rc.tex.y = (float)game->rc.d * game->rc.pre7;
				color_sprite(game, i);
				if ((game->rc.color & 0x00FFFFFF) != 0)
					write_pixel(game->game, *stripe, y, game->rc.color);
				y++;
			}
		}
		(*stripe)++;
	}
}

void	main_sprite(t_game *game, t_parse *data)
{
	int		stripe;
	int		i;

	i = 0;
	while (i < data->nbsprite)
	{
		game->spriteorder[i] = i;
		game->sprite[i]->spritedis = fabs(((data->player.x - game->sprite[i]->x)
		* (data->player.x - game->sprite[i]->x) + (data->player.y -
		game->sprite[i]->y) * (data->player.y * game->sprite[i]->y)));
		i++;
	}
	i = data->nbsprite - 1;
	sort_sprite(data, game);
	while (i >= 0)
	{
		sprite_matrix(game, data, i);
		calcul_sprite_xy(game, data, &stripe);
		game->rc.pre6 = game->rc.spritesize.y * 128;
		game->rc.pre7 = (float)game->sprite[game->spriteorder[i]]->
		sprite[game->sprite[game->spriteorder[i]]->xpm]->
		height / (float)game->rc.spritesize.x / 256.f;
		write_sprite(game, data, i, &stripe);
		i--;
	}
}

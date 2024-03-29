/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:59:00 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/12 17:06:49 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	error_cub(char *error, t_global *env)
{
	if (error)
		print_error(error, false);
	if (env)
		free_cub(env, 1);
	exit(EXIT_FAILURE);
}

void	free_parsing(t_parse *data)
{
	if (!data)
		return ;
	ft_free_tab(data->debug);
	free_spritei(data->s_info, data->nbspritei);
	ft_free_static_tab(data->xpm, 4);
	free(data->floor.xpm);
	free(data->ceiling.xpm);
	free(data->symbol);
	free(data->s_map);
}

void	free_image_bonus(t_global *env)
{
	free_image_tab(4, env->main->menu, env->win.mlx);
	free_image_tab(5, env->main->resume, env->win.mlx);
	free_image_tab(2, env->main->settings, env->win.mlx);
	if (env->main->cur)
		free_image(env->main->cur->img, env->win.mlx);
	free_image(env->main->map, env->win.mlx);
	free_image(env->main->on, env->win.mlx);
	free_image(env->main->logo, env->win.mlx);
	free_image(env->main->hud, env->win.mlx);
}

void	free_game_cub(t_global *env)
{
	free_image(env->game->game, env->win.mlx);
	free_image(env->game->ceiling, env->win.mlx);
	free_image(env->game->floor, env->win.mlx);
	free(env->game->rc.zbuffer);
	free_image_tab(4, env->game->textures, env->win.mlx);
	free(env->game->spriteorder);
	free_sprite_tab(env->game->sprite, env->win.mlx, env->data.nbsprite);
	if (env->win.win)
		mlx_destroy_window(env->win.mlx, env->win.win);
}

void	free_cub(t_global *env, int ret)
{
	free_parsing(&env->data);
	ft_free_tab(env->data.map);
	if (env->op.on)
		free_image_bonus(env);
	if (env->game)
		free_game_cub(env);
	if (env->op.on)
	{
		ft_free_tab(env->data.settings);
		ft_free_tab(env->data.resume);
		ft_free_tab(env->data.tex);
		free(env->main->cur);
		free(env->main);
	}
	free(env->game);
	free(env);
	exit(ret);
}

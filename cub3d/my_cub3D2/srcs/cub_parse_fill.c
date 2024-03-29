/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:26:09 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/15 12:49:22 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int				fill_map(t_parse *data, t_list **maplist)
{
	int			x;
	t_list		*temp;

	x = 0;
	temp = *maplist;
	data->xmap = ft_lstmaxlen(maplist);
	if (!(data->map = malloc((ft_lstsize(temp) + 1) * sizeof(char*))))
		return (1);
	while (temp)
	{
		if (!(data->map[x] = ft_calloc(data->xmap + 1, sizeof(char))))
		{
			data->map[x] = NULL;
			ft_free_tab(data->map);
			return (1);
		}
		ft_strlcpy(data->map[x], (char*)temp->content, data->xmap + 1);
		temp = temp->next;
		x++;
	}
	data->map[x] = NULL;
	data->ymap = ft_tablen(data->map);
	return (0);
}

char			**fill_tab(t_list **list)
{
	char		**tab;
	int			x;
	int			length;
	t_list		*temp;

	x = 0;
	temp = *list;
	length = ft_lstsize(temp);
	if (!(tab = ft_calloc(length + 1, sizeof(char*))))
		return (NULL);
	while (temp)
	{
		if (!(tab[x] = ft_calloc(ft_strlen(temp->content) + 1, sizeof(char))))
		{
			tab[x] = NULL;
			ft_free_tab(tab);
			return (NULL);
		}
		ft_strlcpy(tab[x], (char*)temp->content, ft_strlen(temp->content) + 1);
		temp = temp->next;
		x++;
	}
	tab[x] = NULL;
	return (tab);
}

int				fill_spriteinfo(t_parse *data, t_sinfo_lst **slist)
{
	int			x;
	t_sinfo_lst	*temp;

	x = 0;
	temp = *slist;
	data->nbspritei = ft_lstsize(temp);
	if (!(data->s_info = malloc((data->nbspritei + 1) * sizeof(t_spritei))))
		return (1);
	while (temp)
	{
		if (!(data->s_info[x].xpm_sprite = fill_tab(&(
		(t_sprite_desc*)temp->content)->textures)))
		{
			free_spritei(data->s_info, x);
			return (1);
		}
		data->s_info[x].nsprite = ft_tablen(data->s_info[x].xpm_sprite);
		data->s_info[x].c = ((t_sprite_desc*)temp->content)->c;
		temp = temp->next;
		x++;
	}
	return (0);
}

int				fill_symbol(t_parse *data)
{
	int			x;

	x = 0;
	if (!(data->symbol = ft_calloc((data->nbspritei + 1), sizeof(char))))
		return (1);
	while (x < data->nbspritei)
	{
		if (ft_chrcmp(data->symbol, data->s_info[x].c) == 0)
		{
			return (return_message_c("Same symbol in two sprites: ",
			data->s_info[x].c, 1));
		}
		else if (ft_chrcmp("10NWES", data->s_info[x].c) == 0)
		{
			return (return_message_c(
			"You cannot have a symbol that represents a character in the map: ",
			data->s_info[x].c, 1));
		}
		data->symbol[x] = data->s_info[x].c;
		x++;
	}
	return (0);
}

int				fill_sprite(t_parse *data, t_list **sprite_list)
{
	int			x;
	t_list		*temp;

	x = 0;
	temp = *sprite_list;
	data->nbsprite = ft_lstsize(temp);
	if (!(data->s_map = malloc(data->nbsprite * sizeof(t_spritem))))
		return (1);
	while (temp)
	{
		data->s_map[x].x = ((t_spritem*)temp->content)->x;
		data->s_map[x].y = ((t_spritem*)temp->content)->y;
		data->s_map[x].s_info = ((t_spritem*)temp->content)->s_info;
		temp = temp->next;
		x++;
	}
	return (0);
}

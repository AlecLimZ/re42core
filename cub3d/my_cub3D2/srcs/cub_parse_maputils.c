/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_maputils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:10:12 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/15 16:14:48 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			malloc_map(char *line, t_list **maplist)
{
	t_list	*lsttemp;
	char	*temp;

	temp = NULL;
	if (*maplist == NULL)
	{
		if (!(temp = ft_strdup(line))
			|| !(*maplist = ft_lstnew(temp)))
		{
			free(temp);
			return (return_message_i("Allocation Error", NULL, 1));
		}
	}
	else
	{
		if (!(temp = ft_strdup(line))
			|| !(lsttemp = ft_lstnew(temp)))
		{
			free(temp);
			return (return_message_i("Allocation Error", NULL, 1));
		}
		ft_lstadd_back(maplist, lsttemp);
	}
	return (2);
}

int			check_map(char *line, t_list **maplist)
{
	int		x;

	x = 0;
	while ((line[x] >= 9 && line[x] <= 13) || line[x] == 32)
		x++;
	if (line[x] == '0')
		return (return_message_i("Map need to be circled by 1.", NULL, 1));
	else if (line[x] == '1')
		return (malloc_map(line, maplist));
	else
		return (1);
}

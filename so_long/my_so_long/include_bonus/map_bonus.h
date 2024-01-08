/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:06:39 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/08 18:15:58 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

/**
 * [Component]
 * The component is an element that contains map file.
 * 'p' : player
 * 'e' : exit
 * 'c' : collectible item
 * 'r' : Team Rocket (enemy)
 * */

typedef struct s_compo
{
	int	p;
	int	e;
	int	c;
	int	r;
}	t_compo;

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**coord;
	char	*file;
	t_comp	cnt;
}	t_map;

# define MAP_EXT	".ber"

# define TILE_SIZE	64

typedef struct s_game	t_game;

int		check_ext(char *str, char *ext);
int		check_map_compo(char c);
int		is_map_rectangle(t_game *game, int len2);
int		is_map_walled(t_map maps);
void	count_max_rows_cols(t_game *game, int fd);
void	map_malloc(t_game *game, int fd);
int		open_file(char *filename);
void	map_load(t_game *game, char *filename);
void	get_compo_coord(t_game *game);
void	file_read(t_game *game, char *filename);

#endif

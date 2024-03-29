/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:23:05 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/11 20:10:49 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../ft_printf/includes/libftprintf.h"
# include "mlx.h"
# include "mlx_keys.h"
# include "cub_image.h"
# include "cub_hook.h"
# include "cub_parse.h"
# include "cub_options.h"
# include "cub_mlx.h"
# include "cub_game.h"
# include "cub_bmp.h"
# include "cub_timer.h"

# include <stdio.h>
# include <sys/time.h>
# include <math.h>
# include <stdbool.h>

# define RED_ERROR "\033[1;31m"
# define RESET_ERROR "\033[0m"
# define ORANGE_ERROR "\033[01;33m"
# define GREEN_DEBUG  "\x1B[32m"

# define NO 0
# define SO 1
# define EA 2
# define WE 3

typedef struct		s_global
{
	t_window		win;
	t_menu			*main;
	t_keys			events;
	t_optis			op;
	t_parse			data;
	t_game			*game;
	t_frame			frame;
}					t_global;

/*
**					INIT FUNC
*/
int					init_parse(t_global *env, int ac, char **av);
int					init_xpm(t_parse *data);
void				init_raystruct(t_parse *data, t_game *game);
void				init_ray_so_no(t_parse *data, t_game *game);
void				init_ray_ea_we(t_parse *data, t_game *game);
void				init_precalculated_rc(t_parse *data, t_game *game);
void				init_parse_struct(t_parse *data);
void				start_parse(t_global *env, int fd, char **av);
void				init_bonus(t_global *env);
int					init_debugstr(t_parse *data);
int					init_debugstr_colorxpm(t_parse *data);
int					init_debugstr_tex(t_parse *data);
void				init_game(t_global *env);
void				init_sprites(t_global *env);
int					init_menu(t_parse *data);
int					init_resume(t_parse *data);
int					init_settings(t_parse *data);
void				init_bmp(t_global *env);
int					start_bmp(t_global *env);
int					create_xpm_bonus(t_global *env);

/*
**					ERROR/QUIT
*/
void				error_cub(char *error, t_global *env);
void				free_image_bonus(t_global *env);
void				free_game_cub(t_global *env);
void				free_cub(t_global *env, int exit);
void				free_lst_sinfo(t_sinfo_lst **s_info);
void				free_spritei(t_spritei *s_info, int x);
void				free_parsing(t_parse *data);

/*
**					DATA PRINT
*/
void				ft_printdata(t_parse *data, t_list **maplist,
					t_sinfo_lst **s_info);
void				print_lst_sprite(t_sinfo_lst **s_info);
void				print_spritei(t_spritei s_info);
void				print_lstmap(t_list **spritelist, t_parse *data);

/*
**					PRINT MESSAGE
*/
void				print_error(char *error, bool warn);
void				*return_message(char *error, char *details);
int					return_message_i(char *error, char *details, int err);
int					return_message_c(char *error, char c, int err);
void				credits_message(bool *help);
void				help_message(bool *help);

/*
**					MENU
*/
void				start_button(t_global *env, int x, int y);
void				menu_game(t_global *env);
void				settings_button(t_global *env, int x, int y);
void				resume_game(t_global *env);
void				screen_button(t_global *env, int x, int y);
void				quit_button(t_global *env, int x, int y);

/*
**					SETTINGS MENU
*/
void				settings_menu(t_global *env);
void				return_settings(t_global *env);
void				lowcub_settings(t_global *env);
void				debug_settings(t_global *env);
void				hud_settings(t_global *env);

/*
**					DEBUG MODE
*/
void				main_fps(t_global *env, int x, int y, int color);
void				main_debug(t_global *env, int color);
void				print_debug_fps(t_global *env, int color);
void				print_debug_tex(t_global *env, int color);
void				print_debug_floorceiling(t_global *env, int color);

/*
**					OTHERS
*/
char				*str_from_int(int x, int y, char *desc);
char				*init_str_from_int(t_vec2i *len, int *lenstr, char *desc,
					t_vec2i coord);
void				ft_strcpy_cub(char *src, char *dst);
int					freestr_return(char *str, int exit);
void				ft_free_static_tab(char **tab, int size);
int					ft_strcmp(char *s1, char *s2);

int					loop(t_global *env);
int					loop_bonus(t_global *env);
void				loop_game_bonus(t_global *env);
int					close_window(t_global *env);

#endif

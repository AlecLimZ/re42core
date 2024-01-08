/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:31:49 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/08 17:37:00 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/*-----------------
 * DEBUG OPTION
 * ----------------*/
/* 1 : Debug mode ON
 * 0 : Debug mode OFF */
# define DEBUG		1

/*-----------------
 * GAME MODE OPTION
 * ----------------*/
/* 1 : BONUS MODE
 * 0 : MANDATORY MODE */
# define GAME_MODE	0

/*-----------------
 * ASSET PATH
 * ----------------*/
# define ASSET_PATH	"./asset/"


/*-----------------
 * COMPO OPTION
 * ----------------*/
# define COMPO_P_MAX	1
# define COMPO_C_MAX	1
# define COMPO_E_MAX	1
# define COMPO_R_MAX	0


/*-----------------
 * PLAYER OPTION
 * ----------------*/
/* Player Speed
 * Default	: 4
 * Min		: 1
 * Max		: 64
 * Enter only multiples of 2. */
# define PLAYER_SPEED	4
# define ENEMY_SPEED	8

#endif

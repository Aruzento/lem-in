/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:55:38 by erandal           #+#    #+#             */
/*   Updated: 2020/09/18 16:44:58 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <stdio.h>
# include "mlx.h"

typedef struct		s_rooms
{
	char	*name;
	int		room_status;
	int		id;
	int		x_coord;
	int		y_coord;
	int 	way_num;
	int		link_num;
	struct s_rooms	*link[100000];
}					rooms;

typedef struct	s_lemon
{
	/* Парсинг */
	char	*line;
	int		cmd;
	int		start;
	int		end;

	/* Техническое */
	int		ants;
	int 	room_num;
	int		id;
	int		step;
	int		mtrx[1000][1000];
	rooms	*id_links[100000];
	rooms 	*way[100000];
}				lemon;

int		bfs(lemon *root);
int		get_ants(lemon *root);
void	get_rooms(lemon *root);
void	get_links(lemon *root);
int		li_atoi(char *line, int *ants);
void	err_exit(lemon *gr, char *error_msg);
int		generate_key(char *name);
void	full_free(lemon *root);
#endif
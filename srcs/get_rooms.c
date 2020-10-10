/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 23:46:37 by erandal           #+#    #+#             */
/*   Updated: 2020/09/18 16:01:31 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

char	*get_next_word(char *tmp, int *pos)
{
	char 	*str;
	int		i;

	i = 0;
	while (tmp[*pos + i] && tmp[*pos + i] != ' ')
		i++;
	str = ft_strsub(tmp, *pos, i);
	*pos += i + 1;
	return (str);
}

rooms	*room_create(void)
{
	rooms *room;

	room = (rooms *)malloc(sizeof(rooms));
	room->link_num = 0;
	room->room_status = 0;
	return (room);
}

int		parse_rooms(lemon *root)
{
	int		pos;
	char	*tmp;
	rooms	*room;

	room = room_create();
	pos = 0;
	if (!(room->name = get_next_word(root->line, &pos)))
		return (-1);
	room->id = generate_key(room->name);
	tmp = get_next_word(root->line, &pos);
	if (li_atoi(tmp, &room->x_coord))
		return (-1);
	ft_strdel(&tmp);
	tmp = get_next_word(root->line, &pos);
	if (li_atoi(tmp, &room->y_coord))
		return (-1);
	ft_strdel(&tmp);
	if (root->cmd)
	{
		room->room_status = root->cmd;
		if (root->cmd == 1)
			root->start++;
		else
			root->end++;
		root->cmd = 0;
	}
	root->id_links[root->room_num++] = room;
	if (root->line[pos - 1])
		return (-1);
	return (0);
}

void	parse_cmd(lemon *root)
{
	if (!ft_strcmp(root->line, "##start") || !ft_strcmp(root->line, "##end"))
	{
		if (root->cmd)
			err_exit(root, "\033[31;1mError: Command error!\033[0m");
		else
		{
			root->cmd = (!ft_strcmp(root->line, "##start")) ? 1 : 2;
			if ((root->cmd == 1 && root->start) || (root->cmd == 2 && root->end))
				err_exit(root, "\033[31;1mError: Command error!\033[0m");
		}
	}
}

void	get_rooms(lemon *root)
{
	int ret;

	ret = 0;
	while ((ret = get_next_line(0, &root->line)))
	{
		if (root->line[0] == '#')
			parse_cmd(root);
		else if (ft_strchr(root->line, '-'))
		{
			get_links(root);
			return ;
		}
		else
			if (parse_rooms(root) == -1)
				err_exit(root, "\033[31;1mError: Room line error!\033[0m");
		ft_strdel(&root->line);
	}
	err_exit(root, "\033[31;1mError: No links!\033[0m");
}
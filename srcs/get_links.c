/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:03:34 by erandal           #+#    #+#             */
/*   Updated: 2020/09/16 15:30:37 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

char	*get_next_link(char *tmp, int *pos)
{
	char 	*str;
	int		i;

	i = 0;
	while (tmp[*pos + i] && tmp[*pos + i] != '-')
		i++;
	str = ft_strsub(tmp, *pos, i);
	*pos += i + 1;
	return (str);
}

int		parse_links(lemon *root)
{
	int		pos;
	char	*tmp;
	int 	i;
	int		j;

	i = -1;
	j = -1;
	pos = 0;
	tmp = get_next_link(root->line, &pos);
	while (++i < root->room_num)
		if (!ft_strcmp(root->id_links[i]->name, tmp))
			break ;
	ft_strdel(&tmp);
	if (i == root->room_num)
		return (-1);
	tmp = get_next_link(root->line, &pos);
	while (++j < root->room_num)
		if (!ft_strcmp(root->id_links[j]->name, tmp))
			break ;
	ft_strdel(&tmp);
	if (j == root->room_num)
		return (-1);
	root->id_links[i]->link[root->id_links[i]->link_num] = root->id_links[j];
	root->id_links[j]->link[root->id_links[j]->link_num] = root->id_links[i];
	root->id_links[i]->link_num++;
	root->id_links[j]->link_num++;
	return (0);
}

void	get_links(lemon *root)
{
	int ret;

	if (parse_links(root))
		err_exit(root, "\033[31;1mError: Link line error!\033[0m");
	ft_strdel(&root->line);
	while ((ret = get_next_line(0, &root->line)))
	{
		if (!ft_strchr(root->line, '-') || parse_links(root))
			err_exit(root, "\033[31;1mError: Link line error!\033[0m");
		ft_strdel(&root->line);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:51:18 by erandal           #+#    #+#             */
/*   Updated: 2020/09/16 15:07:41 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	full_free(lemon *root)
{
	int i;

	i = -1;/*
	while (++i < root->room_num)
	{
		printf("%i %i\n|%s| |%s|", i, root->room_num, root->line, root->id_links[i]->name);
		if (root->id_links[i] != NULL)
			free(&root->id_links[i]);
		printf("!\n");
	}*/
	ft_strdel(&root->line);
}

void	err_exit(lemon *root, char *error_msg)
{
	full_free(root);
	if (!errno)
	{
		ft_putendl_fd(error_msg, 2);
		exit(2);
	}
	else
		perror(error_msg);
}
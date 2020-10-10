/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:48:29 by erandal           #+#    #+#             */
/*   Updated: 2020/09/18 16:51:16 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	check_valid(lemon *root)
{
	int i;

	i = -1;
	while (++i < root->room_num)
		if (root->mtrx[root->id_links[i]->x_coord][root->id_links[i]->y_coord] != 1)
			root->mtrx[root->id_links[i]->x_coord][root->id_links[i]->y_coord] = 1;
		else
			err_exit(root, "\033[31;1mError: Same coords!\033[0m");
	if (!root->start || !root->end)
		err_exit(root, "\033[31;1mError: No start or end!\033[0m");
}

void	initial_root(lemon *root)
{
	int i;
	int j;

	i = -1;
	while (++i <= 10)
	{
		j = -1;
		while (++j <= 10)
			root->mtrx[i][j] = 0;
	}
	i = 0;
	while (i++ < 100000)
		root->id_links[i] = NULL;
	root->start = 0;
	root->end = 0;
	root->ants = 0;
	root->step = 0;
	root->room_num = 0;
	root->cmd = 0;
}

void	read_map(lemon *root)
{
	get_ants(root);
	get_rooms(root);
	
	check_valid(root);
}

void	show_room_status(lemon *root)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	while (++i < root->room_num)
		if (root->id_links[i] != NULL)
		{
			/*printf("%i:", root->id_links[i]->id);
			printf("%s:", root->id_links[i]->name);
			printf("%i:", root->id_links[i]->x_coord);
			printf("%i:", root->id_links[i]->y_coord);
			printf("%i:", root->id_links[i]->room_status);
			printf("\033[45m%i\033[0m:*:", root->id_links[i]->way_num);*/
			j = -1;
			/*while (++j < root->id_links[i]->link_num)
				printf("%s:", root->id_links[i]->link[j]->name);
			printf("\n");*/
			if (root->id_links[i]->room_status == 2)
				k = i;
		}
	i = -1;
	/*while (++i <= 10)
	{
		j = -1;
		printf("|");
		while (++j <= 10)
				printf("%c", (root->mtrx[i][j] == 1) ? '*' : ' ');
		printf("|\n");
	}
	i = -1;*/
	while (++i <= root->id_links[k]->way_num)
		printf("%s : ", root->way[i]->name);
	printf("The best way to \033[32m%s\033[0m is \033[32m%i\033[0m - step!\n", root->id_links[k]->name, root->id_links[k]->way_num);
}

int		main()
{
	lemon	root;

	initial_root(&root);
	read_map(&root);

	bfs(&root);
	show_room_status(&root);
	//full_free(&root);
	return (0);
}
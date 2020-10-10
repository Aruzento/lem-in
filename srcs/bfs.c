/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:33:39 by erandal           #+#    #+#             */
/*   Updated: 2020/09/18 16:53:01 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	adventure(lemon *root, int i, int st, int ed, int rt)
{
	int j, k;

	if (i == ed)
	{
		//printf("  \033[31mEnd!\033[0m");
		if (root->id_links[i]->way_num > rt)
			root->id_links[i]->way_num = rt;
		root->way[rt] = root->id_links[i];
		//printf(" %s.way = %i\n", root->id_links[i]->name, root->id_links[i]->way_num);
		return ;
	}
	else
	{
		//printf("  %s.way = %i\n", root->id_links[i]->name, root->id_links[i]->way_num);
		if (root->id_links[i]->way_num > rt)
			root->id_links[i]->way_num = rt;
		k = -1;
		while (++k < root->room_num)
		{
			j = -1;
			while (++j < root->id_links[i]->link_num)
			{
				if (!ft_strcmp(root->id_links[i]->link[j]->name, root->id_links[k]->name) && (root->id_links[k]->way_num > (rt + 1)))
				{
				//	printf("  \033[32mFound new link! Now at :\033[0m %s\n", root->id_links[i]->name);
				//	printf("\t\033[33mLink info: name =\033[0m %s\n", root->id_links[k]->name);
				//	printf("\t\033[33mway_num =\033[0m %i\n", root->id_links[k]->way_num);
				//	printf("  \033[34mSending:\033[0m root, %i, %i, %i, %i\033[34m..\033[0m\n", k, st, ed, rt + 1);
					root->way[rt] = root->id_links[i];
					adventure(root, k, st, ed, rt + 1);
				}
			}
		}
		//printf("\t\033[31mOut from:\033[0m %s\n", root->id_links[i]->name);
	}
}

int		bfs(lemon *root)
{
	int i, st, ed;

	i = -1;
	//printf("\t\033[33mBFS is starting now!\033[0m\n");
	//printf("\n  \033[34mAdding 'st' & 'ed' vars.");
	while (++i < root->room_num)
	{
		if (root->id_links[i]->room_status == 1)
		{
			//printf(".");
			st = i;
		}
		if (root->id_links[i]->room_status == 2)
		{
			//printf(".");
			ed = i;
		}
		root->id_links[i]->way_num = 99999;
	}
	//printf("\033[0m \033[32mComplete! st = %i : ed = %i\033[0m\n\n", st, ed);
	//printf("\t\033[33mAdventure is starting now!\033[0m\n");
	//printf("  \033[34mSending:\033[0m root, %i, %i, %i, 0\033[34m..\033[0m\n", st, st, ed);
	adventure(root, st, st, ed, 0);
	//printf("\t\033[33mAdventure is complete!\033[0m\n");
	return (1);
}
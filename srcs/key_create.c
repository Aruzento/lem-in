/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 13:55:09 by erandal           #+#    #+#             */
/*   Updated: 2020/09/15 03:01:51 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		get_int(char c)
{
	if (ft_isdigit(c))
		return (48 - (int)c);
	else if (c >= 'a' && c <= 'z')
		return (100 + (int)c);
	else if (c >= 'A' && c <= 'Z')
		return (200 + (int)c);
	else
		return (300 + (int)c);
}

int		modul(int num)
{
	int i;

	i = 1;
	while (num)
	{
		i *= 10;
		num /= 10;
	}
	return (i);
}

int		generate_key(char *name)
{
	int i;
	int id;
	int num;

	i = -1;
	id = 0;
	while (name[++i])
	{
		num = get_int(name[i]);
		if (id % modul(num) != num)
			while (num)
			{
				id = id * 10 + num % 10;
				num /= 10;
			}
	}
	return (id);
}
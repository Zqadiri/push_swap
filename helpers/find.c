/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 14:18:44 by zqadiri           #+#    #+#             */
/*   Updated: 2021/05/08 14:22:35 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"

int	find_pos(int *stack, int size, int elem)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	if (size == 0)
		return (-1);
	while (i < size)
	{
		if (stack[i] == elem)
			break ;
		else
			i++;
	}
	return (i);
}

int	find_big_one(int *stack, int size)
{
	int	i;
	int	big;
	int	tmp;

	i = 0;
	big = 0;
	tmp = stack[i];
	while (i < size)
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			big = i;
		}
		i++;
	}
	return (big);
}

int	find_small_one(int	*stack, int size)
{
	int	i;
	int	small;
	int	tmp;

	i = 0;
	small = 0;
	tmp = stack[i];
	while (i < size)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			small = i;
		}
		i++;
	}
	return (small);
}

int	len(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] >= '0' && arg[i] <= '9')
		i++;
	return (i);
}

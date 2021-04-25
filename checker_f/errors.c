/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:07:16 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/18 10:57:57 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	init_struct(t_data *m, int argc )
{
	m->pos = -1;
	m->a_size = argc;
	m->b_size = 0;
	m->stack_b = NULL;
	m->stack_a = NULL;
	m->inst.index = -1;
	m->inst.pivot = -1;
	m->inst.best_rot = NULL;
	m->inst.big = 0;
}

void	*ft_memset(void *str, int val, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)str;
	while (0 < len--)
		ptr[i++] = val;
	return (str);
}

void	init_stacks(t_data *m, int argc)
{
	m->stack_a = malloc(sizeof(int) * (argc));
	if (m->stack_a == NULL)
		exit(EXIT_FAILURE);
	ft_memset(m->stack_a, 0, argc);
	m->stack_b = malloc(sizeof(int) * (argc));
	if (m->stack_b == NULL)
		exit(EXIT_FAILURE);
	ft_memset(m->stack_b, 0, argc);
	m->dup = malloc(sizeof(int) * (argc));
	if (m->dup == NULL)
		exit(EXIT_FAILURE);
	ft_memset(m->dup, 0, argc);
}

int	is_sorted(t_data *m)
{
	int	i;
	int	len;

	i = 0;
	len = m->a_size;
	if (m->b_size != 0)
		return (0);
	while (i < len - 1)
	{
		if (m->stack_a[i] < m->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

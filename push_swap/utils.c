/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 10:07:52 by zqadiri           #+#    #+#             */
/*   Updated: 2021/04/04 11:53:03 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../checker/checker.h"

int sorted(int *dup)
{
   	int i;
	int len;

	i = 0;
	while (dup[i])
	{
		if (dup[i] < dup[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

/* sort the dup to find the perfect pivot   */

void     find_pivot(t_data *m)
{
	int i;
	int index;
	int mid;

	i = 0;
	while (i < m->a_size)
	{
		m->dup[i] = m->stack_a[i];
		i++;
	}
	i = 0;
	for (i = 0; i < m->a_size; i++)
	{
		for (int j = 0; j < (m->a_size - i - 1); j++)
		{
			if (m->dup[j] > m->dup[j + 1])
			{
				int temp = m->dup[j];
				m->dup[j] = m->dup[j + 1];
				m->dup[j + 1] = temp;
			}
		}
	}
	mid = m->dup[m->a_size / 2];
	m->inst.pivot = mid;
	free (m->dup);
	m->dup = NULL;
}

void		fill_dup(t_data *m)
{
	int i;

	i = 0;
	if (!(m->dup = malloc(sizeof(int) * (m->a_size))))
		exit(EXIT_FAILURE);
	m->dup_size = m->a_size;
	while (i < m->a_size)
	{
		m->dup[i] = m->stack_a[i];
		// printf("dup_data --> %d\n", m->dup[i]);
		i++;
	}
}
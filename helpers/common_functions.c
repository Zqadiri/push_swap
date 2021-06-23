/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 10:49:47 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/23 13:09:43 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"

void	exit_error()
{
	write (2, "Error\n", 6);
	exit (EXIT_FAILURE);	
}

void	free_param(char *buff, char*inst)
{
	free(inst);
	inst = NULL;
	free (buff);
	buff = NULL;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 10:15:55 by zqadiri           #+#    #+#             */
/*   Updated: 2021/04/25 10:42:36 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"

int  check_overflow(long digit)
{
	if (digit > INT32_MAX || digit < INT32_MIN)
		return (0);
	return (1);
}

static	char	*ft_join(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	if (!(str = (char *)malloc(i + 2)))
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		flag;

	buffer = (char *)malloc(2);
	if (!line || !(*line = (char *)malloc(1)) || !buffer)
		return (-1);
	*line[0] = '\0';
	while ((flag = read(0, buffer, 1)) > 0)
	{
		buffer[1] = 0;
		if (buffer[0] == '\n')
			break ;
		*line = ft_join(*line, buffer[0]);
	}
	free(buffer);
	return (flag);
}
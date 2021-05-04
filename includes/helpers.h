/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 10:27:46 by zqadiri           #+#    #+#             */
/*   Updated: 2021/04/30 13:43:42 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void		ft_putstr(char const *s);
int			get_next_line(char **line);
char		*ft_strdup(const char *src);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
int			check_overflow(long digit);
void		error_code(int code);
void	    free_param(char *buff, char*inst);
int         ft_strcmp(char *s1, char *s2);
int	        isdigit(int c);
int         find_small_one(int	*stack, int size);
int         find_big_one(int *stack, int size);
int         len(char *arg);

#endif
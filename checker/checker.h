/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:15:23 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/13 10:10:53 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

/*
** Store all the arguments 
*/

typedef struct      s_arg
{
    int            data;
    struct  s_arg *next;
    
}                   t_arg;

typedef struct      s_index
{
    t_arg           arg;
    int             valid_arg;
}                   t_index;

void        is_valid(t_index *index, char *arg);
void        load_list(t_index *index);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:25:07 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/13 10:12:53 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker.h"

/*
** Check duplicate
*/

void    check_duplicate()
{
    
}

/*
** Check Overflow 
*/

static int  check_overflow(unsigned long digit)
{
    if (digit > INT32_MAX && digit < INT32_MIN)
        return (0);
    return (1);
}

/*
** atoi
*/

void    is_valid(t_index *index, char *arg)
{
    unsigned long digit;
    int i;
    int signe;

    i = 0;
    digit = 0;
    signe = 1;
    if (arg[i] == '-')
        signe = -1;
    while (arg[i])
    {
        if (arg[i] >= '0' && arg[i] <= '9')
            digit = (digit * 10) + arg[i] - '0';
        else
            error_code(1);
        i++;
    }
    if (!(check_overflow(digit * signe)))
        error_code (2);
    index->valid_arg = digit * signe;
}

/*
**  Push an element into the list
*/

void    load_list(t_index *index)
{
    
}

int    main(int argc, char **argv)
{
    t_index index;
  
    if (argc < 2)
        return (EXIT_FAILURE);
    ft_bzero(&index, (sizeof(t_index)));
    while (argv[argc])
    {
          is_valid(&index, argv[argc]);
          load_list(&index);
          argc--;
    }
    return (EXIT_SUCCESS);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:25:07 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/13 09:08:07 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker.h"

/*
** Checks if the arguments are digits
*/

void    check_if_digits()
{
    
}

/*
** Check Overflow 
*/

void    check_overflow()
{

}

/*
** Check duplicate
*/

void    check_duplicate()
{
    
}

void    is_valid()
{
    check_if_digits();
    check_overflow();
    check_duplicate();
}

/*
**  Push an element into the list
*/

void    load_list()
{
    
}

int    main(int argc, char **argv)
{
    t_index index;
    
    if (argc < 1)
        error_usage(0);
    ft_bzero(&index, (sizeof(t_index)));
    while (argv)
    {
          is_valid();
          load_list(); 
    }
    return (EXIT_SUCCESS);
}
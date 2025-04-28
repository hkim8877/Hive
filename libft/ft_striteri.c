/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:58:00 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/25 13:58:01 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int    i;

    i = 0;
    while (s[i])
    {
        (*f)(i, &s[i]);
        i++;
    }
}

/*
DESCRIPTION
    Apply the function 'f' to each characters of the string 's', passing its index as a first parameter.
    Each character is transmitted by address to 'f' so it can be modified if necessary.
    The function f directly modifies the value of the character in the original string.
*/

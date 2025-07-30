/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:42:20 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/06/09 16:48:49 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strjoin(char *s1, const char *s2)
{
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (!s2)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}

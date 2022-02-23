/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:53:20 by brattles          #+#    #+#             */
/*   Updated: 2021/09/04 19:05:15 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		s_len;

	s_len = ft_strlen(s) + 1;
	if ((long)(s_len) >= (long)2147483647)
		return (NULL);
	if (!(new_str = (char *)malloc(s_len * sizeof(char))))
		return (NULL);
	ft_strlcpy(new_str, s, s_len);
	return (new_str);
}

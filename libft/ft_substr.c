/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:43:39 by brattles          #+#    #+#             */
/*   Updated: 2021/10/11 22:44:39 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	size_t			len_s;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (!(ptr = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	len_s = 0;
	i = 0;
	while (s[len_s] != '\0')
		len_s++;
	while (s && start < len_s && len--)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return ((char *)ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:39:39 by brattles          #+#    #+#             */
/*   Updated: 2021/09/06 18:39:14 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(strjoin = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	while (i < s1_len)
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[s1_len + s2_len] = '\0';
	return (strjoin);
}

char	*ft_strjoinf(char **s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*ptr;
	char	*s1_copy;

	if (!*s1 || !s2)
		return (NULL);
	s1_copy = *s1;
	len_s1 = 0;
	len_s2 = 0;
	while (s1_copy[len_s1])
		len_s1++;
	// len_s2 = 1;//ft_strlen(s2);
	while (s2[len_s2])
		len_s2++;
	ptr = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (ptr == NULL)
		freex(s1);//free all mem
	if (ptr == NULL)
		return (NULL);
	while (*s1_copy)
		*ptr++ = *s1_copy++;
	while (*s2 != '\0')
		*ptr++ = *s2++;
	*ptr = '\0';
	return (ptr - len_s1 - len_s2 - freex(s1));
}

int	freex(char **s)
{
	if (s)
	{
		free(*s);
		*s = 0x0;
	}
	return (0);
}

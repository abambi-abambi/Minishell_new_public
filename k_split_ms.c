/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_split_ms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:13:39 by abambi            #+#    #+#             */
/*   Updated: 2021/10/19 17:55:24 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_start_errors(char *s)
{
	if (s == NULL)
	{
		syntax_error(4);
		exit(2);
	}
	if (s[0] == ';' && s[1] == '\0')
	{
		syntax_error(3);
		exit(2);
	}
	else if (s[0] == '|' && s[1] == '\0')
	{
		syntax_error(5);
		exit(2);
	}
}

void	check_split_errors2(char *s)
{
	int	i;

	i = 0;
	if (s[i] == ';' && s[i + 1] == ';')
	{
		syntax_error(6);
		exit(2);
	}
	if (s[i] == '|' && s[i + 1] == '|')
	{
		syntax_error(7);
		exit(2);
	}
}

void	check_split_errors(char *s, char c)
{
	char	flag_begin;
	int		i;

	i = 0;
	while (s[i])
	{
		flag_begin = ft_smart_detect_char(&s[i], i);
		if (flag_begin != 0)
		{
			while (s[++i])
			{
				if (ft_smart_detect_char(&s[i], i) == flag_begin)
					break ;
			}
		}
		if (s[i] == c && s[i + 1] == c)
			break ;
		i++;
	}
	check_split_errors2(s);
}

// int	check_gaps_error(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] == ' ')
// 		i++;
// 	if (s[i] == '\0')
// 	{
// 		syntax_error(4);
// 		exit(2);
// 	}
// 	return (0);
// }

char	ft_smart_detect_char(char *str, int i)
{
	if (*str == '\"' && i == 0)
		return (2);
	else if (*str == '\"' && *(str - 1) != '\\')
		return (2);
	else if (*str == '\'' && i == 0)
		return (1);
	else if (*str == '\'' && *(str - 1) != '\\')
		return (1);
	return (0);
}

static int	ft_n_words(char *s, char c)
{
	int		i;
	int		n_words;
	char	flag_begin;

	i = 0;
	n_words = 0;
	while (s[i] != '\0')
	{
		flag_begin = ft_smart_detect_char(&s[i], i);
		if (flag_begin != 0)
		{
			while (s[++i])
			{
				if (ft_smart_detect_char(&s[i], i) == flag_begin)
					break ;
			}
		}
		if (s[i] != c && (n_words == 0 || s[i - 1] == c))
			++n_words;
		i++;
	}
	return (n_words);
}

static int	ft_len_word(char *s, char c)
{
	char	flag_begin;
	int		i;

	if (*s == c)
		s++;
	i = 0;
	while (s[i] && s[i] != c)
	{
		flag_begin = ft_smart_detect_char(&s[i], i);
		if (flag_begin != 0)
		{
			while (s[++i])
			{
				if (ft_smart_detect_char(&s[i], i) == flag_begin)
					break ;
			}
		}
		i++;
	}
	return (i);
}

static int	ft_putstr(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	if (size <= 0)
		return (i);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

static char	**ft_free_malloc(char **arr_ptrs, int j)
{
	while (j >= 0)
		free(arr_ptrs[j--]);
	free(arr_ptrs);
	return (NULL);
}

char	**ft_split_ms(char *arr, char c)
{
	int		n_words;
	char	**arr_ptrs;
	int		i;

	check_start_errors(arr);
	check_split_errors(arr, c);
	// check_gaps_error(arr);
	n_words = ft_n_words(arr, c);
	arr_ptrs = malloc(sizeof(char *) * (n_words + 1));
	if (arr_ptrs == NULL)
		return (NULL);
	i = -1;
	while (++i < n_words)
	{
		if (*arr == c)
			arr++;
		arr_ptrs[i] = malloc(sizeof(char) * (ft_len_word(arr, c) + 1));
		if (arr_ptrs[i] == NULL)
			return (ft_free_malloc(&arr_ptrs[i], i));
		arr += ft_putstr(arr_ptrs[i], arr, ft_len_word(arr, c) + 1);
	}
	arr_ptrs[i] = NULL;
	return (arr_ptrs);
}

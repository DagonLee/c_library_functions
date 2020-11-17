/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:30:59 by da-lee            #+#    #+#             */
/*   Updated: 2020/11/10 19:07:51 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt_word(const char *s, char c)
{
	char	*tmp_str;
	int		cnt;

	tmp_str = (char *)s;
	cnt = 0;
	if (*tmp_str != c)
	{
		tmp_str++;
		cnt++;
	}
	while (*tmp_str)
	{
		while (*tmp_str == c)
		{
			tmp_str++;
			if (*tmp_str != c && *tmp_str)
				cnt++;
		}
		tmp_str++;
	}
	return (cnt);
}

static int	ft_get_word_len(const char *str, char c)
{
	int cnt;

	cnt = 0;
	while (*str != c && *str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

static void	*ft_free_alloc(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	j = 0;
	if (!s || !(arr = malloc(sizeof(char *) * (ft_cnt_word(s, c) + 1))))
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(arr[i] = malloc(sizeof(char) * (ft_get_word_len(s, c)))))
				return (ft_free_alloc(arr));
			while (*s && *s != c)
				arr[i][j++] = (char)*s++;
			arr[i][j] = 0;
			i++;
			j = 0;
		}
	}
	arr[i] = 0;
	return (arr);
}

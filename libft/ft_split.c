/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunar <egunar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:15:13 by egunar            #+#    #+#             */
/*   Updated: 2022/01/05 11:19:54 by egunar           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *s, char c)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			res++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	if (!s || c < 0)
		return (NULL);
	res = malloc((count_word(s, c)) * sizeof(char *));
	if (!res)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c && ++j)
				++s;
			res[i++] = ft_substr(s - j, 0, j);
		}
		else
			++s;
	}
	res[i] = 0;
	return (res);
}

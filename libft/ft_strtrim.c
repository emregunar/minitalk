/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunar <egunar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:21:37 by egunar            #+#    #+#             */
/*   Updated: 2022/01/05 17:39:42 by egunar           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	trimle(const char s1, char const *s2)
{
	int	j;

	j = 0;
	while (s2[j])
	{
		if (s1 == s2[j])
		{
			return (1);
		}
		j++;
	}
	return (0);
}

char	*isi_yap(int start, int end, char *substr, const char *s1)
{
	int	i;

	i = 0;
	if (start >= end)
		return (substr);
	while (start < end)
	{
		substr[i] = s1[start];
		i++;
		start++;
	}
	substr[i] = 0;
	return (substr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*substr;
	int		i;
	int		len;
	int		end;
	int		start;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) - 1;
	i = -1;
	while (s1[len] && trimle(s1[len], set))
		len--;
	end = len - 1;
	while (s1[++i] && trimle(s1[i], set))
		len--;
	start = i;
	if (len < 0)
		return (ft_strdup(""));
	substr = malloc(sizeof(char) * (len + 2));
	if (!substr)
		return (0);
	return (isi_yap(start, end + 2, substr, s1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunar <egunar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:30:38 by egunar            #+#    #+#             */
/*   Updated: 2022/01/05 11:23:26 by egunar           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*newstr;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = 0;
	newstr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{	
		newstr[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		newstr[j++] = s2[i];
		i++;
	}	
	newstr[j] = '\0';
	return (newstr);
}

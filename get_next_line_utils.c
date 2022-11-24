/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:12:36 by iecharak          #+#    #+#             */
/*   Updated: 2022/11/23 20:37:00 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (s && *s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}
// int	ft_strchr(const char *s, int c)
// {
// 	int i;
// 	i = 0;

// 	while (s && s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
//}
// char	*ft_strdup(const char *s1)
// {
// 	char	*s2;
// 	size_t	len;
// 	size_t	i;

// 	i = 0;
// 	len = ft_strlen(s1);
// 	s2 = malloc(sizeof(char) * (len + 1));
// 	if (!s2)
// 		return (NULL);
// 	while (i < len)
// 	{
// 		s2[i] = s1[i];
// 		i++;
// 	}
// 	s2[i] = '\0';
// 	return (s2);
// }

// char	*ft_strjoin(char *s1, char  *s2)
// {
// 	int	i;
// 	int	j;
// 	char *c;

// 	if (!s1)
// 	{
// 		s1 = ft_strdup("");
// 	}
// 	c = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!c)
// 		return (NULL);
// 	j = 0;
// 	while (s1[j])
// 	{
// 		c[j] = s1[j];
// 		j++;
// 	}
// 	i = 0;
// 	while (s2[i])
// 	{
// 		c[j] = s2[i];
// 		j++;
// 		i++;
// 	}
// 	c[j] = '\0';
// 	return (c);
// }

// void	ft_add_to_stash(char *stash, char *buffer, int readed)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (stash[i])
// 		i++;
// 	stash = malloc(sizeof(char) * (i + readed));
// 	if (!stash)
// 		return ;
// 	while (buffer[j])
// 	{
// 		stash[i] = buffer[j];
// 		i++;
// 		j++;
// 	}
// 	stash[i] = '\0';
// 	return ;
// }

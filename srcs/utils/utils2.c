/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:06:58 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/30 16:07:00 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ms_head.h"


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (1);
	if (!s2)
		return (1);
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp1(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (1);
	if (!s2)
		return (1);
	while (s1[i] || s2[i])
	{
		if (ft_tolower(s1[i]) < ft_tolower(s2[i]))
			return (1);
		if (ft_tolower(s1[i]) > ft_tolower(s2[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strrchr1(char *str, int c)
{
	char	*h;
	char	a;
	int		j;

	h = (char *)str;
	j = 0;
	a = (char) c;
	while (h[j])
		j++;
	while (j >= 0)
	{
		if (h[j] == a)
		{
			h[j] = 0;
			return (str);
		}
		j--;
	}
	return (0);
}

int	ft_strcmp2(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (0);
	else if (!s2)
		return (1);
	//printf("%s -- %s\n", s1, s2);
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
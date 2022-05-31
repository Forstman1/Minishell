/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:19:40 by            #+#    #+#             */
/*   Updated: 2022/05/27 18:19:41 by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../ms_head.h"

char	*pwd(t_env *env)
{
	t_env *lst;

	lst = env;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "PWD"))
		{
			if (lst->value)
				return (lst->value);
			else
				return (NULL);
		}
		lst = lst->next;
	}
	return (NULL);
}

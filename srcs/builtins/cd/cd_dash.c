/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_dash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:37:59 by sahafid           #+#    #+#             */
/*   Updated: 2022/06/01 14:38:00 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../ms_head.h"

void	cd_dash(t_env *env, char *arg)
{
	t_env	*lst;
	char	*OLDPWD;
	int		i;

	lst = env;
	i = 1;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "OLDPWD"))
		{
			if (lst->value)
			{
				OLDPWD = lst->value;
				printf("%s\n", OLDPWD);
				lst->value = pwd(env, 0);
			}
			i = 0;
			break ;
		}
		lst = lst->next;
	}
	if (i == 1)
	{
		printf("OLDPWD not set");
		exit(0);
	}
	lst = env;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "PWD"))
		{
			lst->value = OLDPWD;
			break ;
		}
		lst = lst->next;
	}
}
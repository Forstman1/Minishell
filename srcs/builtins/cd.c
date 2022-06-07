/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:07:37 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/29 16:07:38 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../ms_head.h"


// void	cd_env(t_env *env, char	*str, char *arg)
// {
// 	int		i;
// 	char	**splited;
// 	char	*joined;

// 	i = 0;
// 	joined = NULL;
// 	if (!ft_strcmp(arg, NULL))
// 		cd_home(env, arg);
// 	else if (!ft_strcmp(arg, ".."))
// 		cd_back(env, arg);
// 	else if (!ft_strcmp(arg, "."))
// 		i++;
	
// 	else if (!ft_strcmp(arg, "/"))
// 		cd_root(env, arg);
// 	else if (!ft_strcmp(arg, "./"))
// 		cd_samdir(env, arg);
// 	else
// 	{
// 		if (arg[0] == '/')
// 			cd_root(env, arg);
// 		splited = ft_split(arg, '/');
// 		i = 0;
// 		while (splited[i])
// 		{
// 			if (!ft_strcmp(splited[i], "."))
// 				i++;
// 			else if (!ft_strcmp(splited[i], ".."))
// 			{
// 				cd_back(env, arg);
// 				i++;
// 			}
// 			else
// 			{
// 				if (!joined)
// 					joined = ft_strjoin(pwd(env, 0), "/");
// 				joined = ft_strjoin(joined, "/");
// 				joined = ft_strjoin(joined, splited[i]);
// 				i++;
// 			}
// 		}
// 		if (chdir(joined))
// 		{
// 			printf("not sush directory\n");
// 			return ;
// 		}
// 		joined = ft_strjoin("PWD=", joined);
// 		export_env(&env, joined);
// 		joined = NULL;
// 		// cd_path(env, arg);
// 	}
// }

void	check_oldpwd(t_env *env, char	*oldpwd)
{
	t_env *lst;

	lst = env;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "OLDPWD"))
		{
			if (oldpwd)
				lst->value = oldpwd;
			else
				lst->value = "";
			return ;
		}
		lst = lst->next;
	}
	lst = ft_lstnew1("OLDPWD", "");
	ft_lstadd_back1(&env, lst);
}

void	cd_env(t_env *env, char	*str, char *arg)
{
	t_env	*lst;
	char	*dir;
	char	*oldpwd;
	int		i;

	lst = env;
	dir = NULL;
	oldpwd = NULL;
	i = 0;
	
	if (!ft_strcmp(arg, NULL))
		cd_home(env, arg);
	else if (!ft_strcmp(arg, "-"))
		cd_dash(env, arg);
	else
	{
		if (chdir(arg))
		{
			printf("not sush directory\n");
			return ;
		}
		while (lst)
		{
			if (!ft_strcmp(lst->key, "PWD"))
			{
				if (lst->value)
					oldpwd = lst->value;
				lst->value = getcwd(dir, 9999);
				i = 1;
				break ;
			}
			lst = lst->next;
		}
		if (i == 0)
		{
			lst = ft_lstnew1("PWD", getcwd(dir, 9999));
			ft_lstadd_back1(&env, lst);
		}
		check_oldpwd(env, oldpwd);
	}
}
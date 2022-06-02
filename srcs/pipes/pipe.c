/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:08:22 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/29 16:08:23 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../ms_head.h"


void	execute_func(t_env	*env, t_arg *arg)
{
	int i;

	i = fork();
	if (i == 0)
		execve(arg->cmd_path, arg->cmd, arg->paths);
}

void	check_path(t_env	*env, t_arg *arg)
{
	t_env	*lst;
	int		i;

	lst = env;
	i = 0;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "PATH"))
		{
			if (lst->value)
			{
				arg->paths = ft_split(lst->value, ':');
				i = 1;
			}
			break ;
		}
		lst = lst->next;
	}
	if (i != 1)
	{
		printf("PATH not found\n");
		exit(0);
	}
}

void	check_cmd(t_env	*env, t_arg *arg, char *str)
{
	char	*cmd_path;
	char	*tmp;
	int		i;

	i = 0;
	arg->i++;
	if (arg->i == 2)
	{
		pipe(arg->fd);
		dup2(arg->fd[1], 0);
	}
	while (arg->paths[i])
	{
		cmd_path = ft_strjoin(arg->paths[i], "/");
		tmp = cmd_path;
		cmd_path = ft_strjoin(cmd_path, str);
		free(tmp);
		if (!access(cmd_path, X_OK))
		{
			arg->cmd_path = cmd_path;
			arg->cmd = ft_split(str, ' ');
			return ;
		}
		i++;
	}
	printf("Command if not found\n");
	exit(0);
}

int	builtins(t_env	*envi, char *str)
{
	if (!ft_strcmp(str, "pwd"))
	{
		pwd(envi, 1);
		return (1);
	}
	else if (!ft_strcmp(str, "export"))
	{
		export_env(&envi, str);
		return (1);
	}
	else if (!ft_strcmp(str, "unset"))
	{
		unset_env(&envi, str);
		return (1);
	}
	else if (!ft_strcmp(str, "env"))
	{
		env(envi);
		return (1);
	}
	else if (!ft_strcmp(str, "exit"))
	{
		exit10();
	}
	return (0);
}

void	check_command(t_env	*env, t_arg *arg)
{
	t_env	*lst;
	int i;

	lst = env;
	i = 1;
	arg->i = 0;
	check_path(env, arg);
	while (arg->args[i])
	{
		if (!ft_strcmp(arg->args[i], "|") || !ft_strcmp(arg->args[i], ">"))
			i++;
		else if (builtins(env, arg->args[i]))
			i++;
		else
		{
			check_cmd(env, arg, arg->args[i]);
			execute_func(env, arg);
			i++;
		}
	}
}


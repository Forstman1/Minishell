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


void	execute_func(t_env	*env, t_arg *arg, int j)
{
	int i;

	i = fork();
	if (i == 0)
	{
		if (j == 1)
			dup2(arg->fd[1], 1);
		else if (j == 2)
		{
			dup2(arg->fd[0], 0);
			dup2(arg->fd1[1], 1);
		}
		else
		{
			dup2(arg->fd1[0], 0);
		}
		execve(arg->cmd_path, arg->cmd, arg->paths);
	}
}


void	check_command(t_env	*env, t_arg *arg)
{
	t_env	*lst;
	int		i;
	int		id;
	int		j;
	int		fd;

	lst = env;
	i = 0;
	id = 0;
	j = 0;
	arg->i = 0;
	check_path(env, arg);
	while (arg->args[i])
		i++;
	if (i == 1)
	{
		i = 0;
		if (check_builtins(env, arg->args[i]))
		{
			builtins(env, arg->args[i]);
			return ;
		}
	}
	i = 0;
	while (arg->args[i])
	{
		if (!ft_strcmp(arg->args[i], "|"))
			i++;
		else if (check_builtins(env, arg->args[i]))
		{
			id = fork();
			if (id == 0)
			{
				builtins(env, arg->args[i]);
				exit(0);
			}
			i++;
		}
		else
		{
			j = check_cmd(env, arg, arg->args[i]);
			if (j == 1)
			{
				if (arg->args[i - 1] != NULL && arg->args[i + 1] != NULL)
				{
					execute_func(env, arg, 2);
				}
				else if (arg->args[i + 1] != NULL)
				{
					pipe(arg->fd);
					execute_func(env, arg, 1);
				}
				else
				{
					execute_func(env, arg, 0);
					// close(arg->fd);
				}
				i++;
			}
			else
				return ;
		}
	}
}

		// else if (!ft_strcmp(arg->args[i], "<"))
		// {
		// 	i++;
		// 	fd = open(arg->args[i], O_CREAT, O_WRONLY);
		// 	dup2(fd, 0);
		// 	i++;
		// }
		// else if (!ft_strcmp(arg->args[i], ">"))
		// {
		// 	i++;
		// 	fd = open(arg->args[i], O_CREAT, O_WRONLY);
		// 	dup2(fd, 1);
		// 	i++;
		// }
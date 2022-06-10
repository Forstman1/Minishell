/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:        <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:                     by                   #+#    #+#             */
/*   Updated:                     by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_head.h"

void	create_env(t_env **env, char **envirement, int i)
{
	t_env	*lst;
	int		j;
	char	*key;
	char	*value;

	j = 0;
	while (i > 0)
	{
		value = ft_strdup(envirement[j]);
		value = ft_strchr(value, '=') + 1;
		key = ft_strdup(envirement[j]);
		key = get_keys(key, '=');
		lst = ft_lstnew1(key, value);
		ft_lstadd_back1(env, lst);
		j++;
		i--;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_env	*envi;
	t_arg	arg;
	int		i;

	i = 0;
	while (env[i])
		i++;
	create_env(&envi, env, i);
	while (1)
	{
		arg.str = NULL;
		arg.str = readline("");
		// signals();
		arg.args = NULL;
		arg.args = ft_split(arg.str, '|');
		check_command(envi, &arg);
		i = 0;
		while (arg.args[i])
		{
			free(arg.args[i]);
			arg.args[i] = NULL;
			i++;
		}
		arg.str = NULL;
	}
	return (0);
}
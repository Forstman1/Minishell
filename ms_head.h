/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:        <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:                     by                   #+#    #+#             */
/*   Updated:                     by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_HEADER_H
#define MS_HEADER_H

/* ---------------------------------- Libraries ----------------------------- */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>


/* ----------------------------------- Enums -------------------------------- */
typedef enum e_enum
{
	OPT1,
	OPT2,
	OPT3,
} t_enum;

/* ---------------------------------- TypeDefs ------------------------------ */
typedef unsigned int t_uint;
typedef unsigned long t_ulong;
typedef unsigned char t_uchar;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
} t_env;

typedef struct s_arg
{
	char	*str;
} t_arg;


void	ft_lstadd_back1(t_env **lst, t_env *new);
t_env	*ft_lstnew1(char *key, char *value);
char	*get_keys(char *str, int c);
char	*pwd(t_env *env);
void	export_env(t_env **env, char *find);
void	unset_env(t_env **env, char *find);
int		ft_strcmp(char *s1, char *s2);
void	pipes();
void	cd_env(t_env *env, t_arg *arg);
void	cd_path(t_env *env, t_arg *arg);
char	*ft_strrchr1(char *str, int c);
void	cd_back(t_env *env, t_arg *arg);
void	cd_home(t_env *env, t_arg *arg);
void	cd_root(t_env *env, t_arg *arg);
void	cd_samdir(t_env *env, t_arg *arg);



/* --------------------------------- Prototypes ----------------------------- */
#endif 
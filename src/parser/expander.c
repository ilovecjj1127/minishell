/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:39:12 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/12/20 18:20:04 by kkopnev       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


/* find the variable in the env. Never return NULL, 
only can be empty string!! */
char	*find_variable(char *var, char **env, int exit_c)
{
	int		i;
	char	*content;

	if (*var == '?')
		return (ft_itoa(exit_c));
	i = 0;
	var = ft_strjoin(var, "="); //not free original var
	while (env[i] && ft_strncmp(env[i], var, ft_strlen(var)) != 0)
		i++;
	if (env[i])
		content = ft_strdup(env[i] + ft_strlen(var));
	else
		content = ft_calloc(sizeof(char), 1);
	if (!content)
		perror("malloc"); // todo: write another error() to exit(0)
	if (!env[i])
		content[0] = '\0';
	free(var);
	return (content);
}

t_lexer	*ft_lexsplit(t_lexer **lst, t_lexer *lexer, char *str)
{
	char	**tabs;
	t_lexer	*node;
	int		i;
	
	tabs = ft_split(str, ' ');
	i = -1;
	while (*str)
	{
		if (*str == ' ')
		{
			node = ft_lexnew(ft_strdup(" "), WHITE_SPACE);
			while (*str == ' ')
				str++;
		}
		else
		{
			node = ft_lexnew(tabs[++i], WORD);
			str += ft_strlen(tabs[i]);
		}
		ft_lexinsert(lst, lexer->prev, lexer, node);		
	}
	ft_lexdel(ft_lexretract(lst, lexer));
	free(tabs); //only free the crust? not strings
	return (node->next);
}

void	expand_env(t_lexer **lst, char **env, int exit_c)
{
	char	*tmp;
	t_lexer	*lex;
	
	lex = *lst;
	while (lex)
	{
		if (lex->token == ENV)
		{
			tmp = find_variable(lex->content + 1, env, exit_c);
			if (arr_len(tmp, ' ') != 1 && lex->prev && (lex->prev->token == '<' \
				|| lex->prev->token == '>' || lex->prev->token == DREDIR_OUT))
				exit(1); // error("ambiguous redirect");
			if (ft_strchr(tmp, ' ') && lex->state == GENERAL)
			{
				lex = ft_lexsplit(lst, lex, tmp);
				free(tmp);
				continue;
			}
			ft_lexinsert(lst, lex->prev, lex, ft_lexnew(tmp, WORD));
			lex = lex->prev;
			ft_lexdel(ft_lexretract(lst, lex->next));
		}
		lex = lex->next;
	}
}

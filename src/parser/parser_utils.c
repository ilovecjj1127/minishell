/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 10:28:30 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/12/13 15:41:33 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd*	ft_cmdnew(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->args = NULL;
    // int				(*builtin)(t_tools *, struct s_cmd *);
    cmd->num_redir = 0;
	cmd->redir= NULL;
    cmd->prev = NULL;
    cmd->next = NULL;
	return (cmd);
}

void	ft_cmdaddfront(t_cmd** cmd, t_cmd* new)
{
    if (new == NULL)
    {
        return ;
    }
	new->next = *cmd;
    if (*cmd != NULL)
    {
        (*cmd)->prev = new;
    }
	*cmd = new;
}

void	ft_cmdaddback(t_cmd **cmd, t_cmd *new)
{
    t_cmd* last;

    last = NULL;
	if ((*cmd) == NULL)
		ft_cmdaddfront(cmd, new);
	else
    {
        last = ft_cmdlast(*cmd);
		last->next = new;
        new->prev = last; 
        new->next = NULL;
    }
}

t_cmd*	ft_cmdlast(t_cmd* cmd)
{
	if (cmd == NULL)
		return (NULL);
	while (cmd->next != NULL)
		cmd = cmd->next;
	return (cmd);
}

void	ft_cmddel(t_cmd* node)
{
    int i;

    i = -1;
    if (node->args)
    {
        while((node->args)[++i])
            free((node->args)[i]);
    }
    free(node->args);   
	free(node);
}

void    ft_cmdclean(t_cmd** cmd)
{
    t_cmd*    temp;
    
    temp = NULL;
    while(*cmd)
    {   
        temp = *cmd;
        *cmd = (*cmd)->next;
        ft_cmddel(temp);
    }
}
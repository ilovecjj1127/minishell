/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 16:11:54 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/12/11 14:45:27 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * to read: <termio.h>
 * 			metacharacters(what are they how to interpret them)
 * to read: how pinkshell deal with the quotes DONE
 * discuss: what tokens should be used (what should we expand??) DONE
 * discuss: what should be done for the case of " "h h h" DONE
 * check: what protection should we use for diffrent functions -- PROTECTION FILE
 * discuss: adding a global struct which stores all the other structs DONE
 * check: the manual for $ and evironmental variables 
 * TO DO: the big struct
 * TO DO: create the copy of the env
 * 
*/
int	main(int argc, char **argv, char **env)
{
	char	*line;
	int		exit_status;
	t_lexer*	lexer;
	t_parser*	parser;
	
	exit_status = 0;
	while (1)
	{
		line = readline("minishell:");
		// TO DO: error control
		if (line && *line )
			add_history(line);
		if (!check_quotes(line)) // TO Do: check if the quotes are closed
		//	write(:didn't clode the quotes);
		//	continue;						
		// LEXER PART
		// lexer = ft_lexer(line);
		// protection
		// expander(lexer, env, exit status);
		// parser = ft_parser(lexer, env);
		// executor(parser, env, exit_status);
		// cleaner(lexer, parser);
		
	}
}
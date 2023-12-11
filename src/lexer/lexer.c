/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 11:09:00 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/12/08 15:10:10 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// CHECK: WHEATHER WE NEED BACKSLASH IN OUR TOKENS OF D_QUOTE OR QUOTE
// CHECK: DO WE NEED \n AS TOKEN and \ ?

// ALGO:

// INPUT: String;
// OUTPUT: LL with lexical parts
// Go character by character through the string
// if you find:
// 		- WHITE SPACE
//		- QUOTE
//		- DQUOTE
//		- PIPE
//	CREATE A NODE WITH A TOKEN OF THE CORRESPONDING TYPE
// if you find
//		- ENV
//	TAKE EVERYTHING AFTER UNTIL THE WHITE SPACE OR $
//	AND CREATE A NODE FOR THIS THING WITH TYPE ENV
//	
//	If you find
//	- REDIR_IN
//	CHECK WHEATHER THE NEXT CHAR IS ALSO REDIR_IN
//	If it is, then take the last two characters and
//	create a node for them with token of type HERE_DOC
//	If it is not, then create a node for it with type
//	REDIR_IN;
//
//	If you find
//	- REDIR_OUT
//	CHECK WHEATHER THE NEXT CHAR IS ALSO REDIR_OUT
//	If it is, then take the last two characters and
//	create a node for them with token of type DREDIR_OUT
//	If it is not, then create a node for it with type
//	REDIR_OUT;
//
//	If it is nothing of that, then
//	THIS IS A WORD
//	Thus, create a node for everything starting from the first
//	letter to the first space that you find and assign token WORD
//	to it.

//	THEN ADD THE NODE TO THE LL;

//	Now the part for setting the state
//	WE WILL USE THE STATE TO TRACK THE STATE 
//	ITERATEVELY GO THROUGH LINKED LIST 
//	AND ASSIGN THE PROPER STATE TO IT DEPENDING WHEATHER IT IS IN THE QUOTE OR NOT


// TO DO:
/**
 	1. Functions for linked list:
		
		1) Create a node for linked list;
		2) Add back to LL;
		3) Clear LL;
	
	2. A FUNCTION FOR CREATION OF OUR LL WITH THE CONTENT, TOKENS AND LENGTH; 
	3. A FUNCTION FOR SETTING THE STATE;
	
*/

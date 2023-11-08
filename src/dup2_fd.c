/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:20:58 by ealbayra          #+#    #+#             */
/*   Updated: 2023/11/08 16:46:03 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

void	_create_dup(t_shell *m_shell)
{
	int		new_fd[2];

	pipe(new_fd);
	write(new_fd[1], m_shell->heredoc,
		ft_strlen(m_shell->heredoc));
	dup2(new_fd[0], 0);
	close (new_fd[1]);
	close(new_fd[0]);
}

void	create_dup(t_shell *m_shell, t_mparse *parse)
{
	(void)m_shell;
	if (parse->infile > STDERR)
		dup2(parse->infile, 0);
	if (parse->outfile > STDERR)
		dup2(parse->outfile, 1);
}

void	create_dup_one(t_mparse *parse, int *fd)
{
	t_mparse	*nparse;

	nparse = parse->next;
	close(fd[0]);
	if (parse->next && fd && nparse->cmd)
		dup2(fd[1], 1);
	else if (parse->type == HEREDOC && parse->next->next)
		dup2(fd[1], 1);
	close(fd[1]);
}

void	create_dup_two(t_mparse *parse, int *fd, int fd_index, t_shell *m_shell)
{
	(void)fd_index;
	close(fd[1]);
	if (parse->type == HEREDOC)
		_create_dup(m_shell);
	else if (fd)
		dup2(fd[0], 0);
	close(fd[0]);
}

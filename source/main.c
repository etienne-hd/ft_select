/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 21:30:02 by ehode             #+#    #+#             */
/*   Updated: 2026/05/27 00:44:45 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "libft.h"
#include "select.h"
#include "terminal.h"
#include <sys/types.h>
#include <termcap.h>
#include <termios.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_ctx	ctx;
	uint	code;

	if (argc == 1)
		return (0);
	ctx = init_ctx(argc, argv);
	if (!ctx.choice_state)
	{
		ft_putstr_fd("Unable to init ctx.\n", 2);
		return (1);
	}
	enter_terminal(&ctx.term);
	code = ft_select(&ctx);
	restore_terminal(&ctx.term);
	if (code == 2)
		show_selected(&ctx);
	destroy_ctx(&ctx);
}

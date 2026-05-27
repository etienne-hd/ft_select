/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:09:06 by ehode             #+#    #+#             */
/*   Updated: 2026/05/28 00:15:37 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H
# include "keyboard.h"
# include <sys/types.h>
# define MARGIN 1

# include "ctx.h"

void	show_selected(t_ctx *ctx);
uint8_t	ft_select(t_ctx *ctx);

void	init_signal(t_ctx *ctx);

void	render(t_ctx *ctx);

void	on_resize(t_ctx *ctx);
void	on_key(t_ctx *ctx, t_key *key);

#endif
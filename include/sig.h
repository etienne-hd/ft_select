/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 04:04:48 by ehode             #+#    #+#             */
/*   Updated: 2026/05/27 04:04:48 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H
# include "ctx.h"

void	signal_handler(int signal);
void	init_signal(t_ctx *ctx);

void	on_resize(t_ctx *ctx);
void	on_quit(t_ctx *ctx);
void	on_stop(t_ctx *ctx);
void	on_continue(t_ctx *ctx);

#endif
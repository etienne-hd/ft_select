#ifndef SIG_H
# define SIG_H
#include "ctx.h"

void	signal_handler(int signal);
void	init_signal(t_ctx *ctx);

void	on_resize(t_ctx *ctx);
void	on_quit(t_ctx *ctx);
void	on_stop(t_ctx *ctx);
void	on_continue(t_ctx *ctx);

#endif
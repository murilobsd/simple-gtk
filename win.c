/*
 * Copyright (c) 2020 Murilo Ijanc' <mbsd@m0x.ru>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <string.h>
#include <stdlib.h>

#include "win.h"

#define SELF ((struct win_impl *)w)
#define GWIN GTK_WINDOW

struct win_impl {
	win_methods_t 	*methods;

	int		 width;
	int		 height;
	char		*title;
	GtkWidget	*gwin;
};


static int	   set_width(win_t *, int);
static int	   set_height(win_t *, int);
static int	   set_title(win_t *, const char *);
static void	   show(win_t *);

static win_methods_t w_methods = {
	set_width,
	set_height,
	set_title,
	show
};

static int
set_width(win_t *w, int width)
{
	if (width <= 0)
		return (-1);

	SELF->width = width;

	return (0);
}

static int
set_height(win_t *w, int height)
{
	if (height <= 0)
		return (-1);

	SELF->height = height;

	return (0);
}

static int
set_title(win_t *w, const char *title)
{
	if (title == NULL)
		return (-1);

	SELF->title = strdup(title);
	gtk_window_set_title(GWIN(SELF->gwin), (const gchar *)title);

	return (0);
}

static void
show(win_t *w)
{
	gtk_window_set_default_size(GWIN(SELF->gwin), SELF->width, SELF->height);
	gtk_widget_show(SELF->gwin);
}

void
win_free(win_t *w)
{
	if (w == NULL)
		return;
	free(w);
}

win_t *
win_new(void)
{
	struct win_impl *w;

	w = calloc(1, sizeof(struct win_impl));
	if (w == NULL)
		return NULL;

	w->gwin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	w->methods = &w_methods;

	return (win_t *)w;
}

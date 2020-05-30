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

#include "win.h"

//#include <gtk/gtk.h>
/*
void close_app(GtkWidget *, gpointer *);
*/
int
main(int argc, char *argv[])
{
	win_t *win = NULL;

	gtk_init(&argc, &argv);

	win = win_new();
	win->methods->set_width(win, 300);
	win->methods->set_height(win, 200);
	win->methods->set_title(win, "Hiiii");
	win->methods->show(win);

	/* FIX: callback free window */
	// win_free(win);
	gtk_main();

	return (0);
}
/*
void
close_app(GtkWidget *widg, gpointer *data)
{
	gtk_main_quit();
}
*/

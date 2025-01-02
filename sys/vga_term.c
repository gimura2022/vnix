/*
	Permission to use, copy, modify, and/or distribute this software for
	any purpose with or without fee is hereby granted.

	THE SOFTWARE IS PROVIDED “AS IS” AND THE AUTHOR DISCLAIMS ALL
	WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES
	OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE
	FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY
	DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
	AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
	OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

/*
	AUTHOR: gimura2022 <gimura0001@gmail.com>
	DATE  : 2.1.2025
	FILE  : sys/vga_tty.c

	vga interface for tty
*/

#include <vnix/vga_term.h>
#include <vnix/dev_tty.h>
#include <vnix/vga.h>

static void vga_putchar(char c);

void vga_term(struct terminal* term)
{
	tty_create(term, VGA_WIDTH, VGA_HEIGHT);

	term->clear      = vga_clear;
	term->putchar    = vga_putchar;
	term->set_cursor = vga_move_cursor;
}

static void vga_putchar(char c)
{
	vga_add_char(c, 0x07);
}

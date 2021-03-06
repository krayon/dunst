/* copyright 2013 Sascha Kruse and contributors (see LICENSE for licensing information) */

#ifndef DUNST_DUNST_H
#define DUNST_DUNST_H

#include <glib.h>
#include <stdio.h>
#include <stdbool.h>

#include "notification.h"

#define ERR(msg) printf("%s : %d\n", (msg), __LINE__)
#define PERR(msg, errnum) printf("(%d) %s : %s\n", __LINE__, (msg), (strerror(errnum)))
#define LENGTH(X)               (sizeof X / sizeof X[0])

#define ColLast 3
#define ColFrame 2
#define ColFG 1
#define ColBG 0

extern GQueue *queue;
extern GQueue *displayed;
extern GQueue *history;
extern GSList *rules;
extern bool pause_display;
extern const char *color_strings[3][3];

/* return id of notification */
gboolean run(void *data);
void wake_up(void);

int dunst_main(int argc, char *argv[]);

void check_timeouts(void);
void history_pop(void);
void history_push(notification *n);
void usage(int exit_status);
void move_all_to_history(void);
void print_version(void);
char *extract_urls(const char *str);
void context_menu(void);
void wake_up(void);
void pause_signal_handler(int sig);

#endif
/* vim: set tabstop=8 shiftwidth=8 expandtab textwidth=0: */

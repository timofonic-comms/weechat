/*
 * Copyright (c) 2003-2005 by FlashCode <flashcode@flashtux.org>
 * See README for License detail, AUTHORS for developers list.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#ifndef __WEECHAT_COMPLETION_H
#define __WEECHAT_COMPLETION_H 1

#include "weelist.h"

#define COMPLETION_NULL         0
#define COMPLETION_NICK         1
#define COMPLETION_COMMAND      2
#define COMPLETION_COMMAND_ARG  3

typedef struct t_completion t_completion;

struct t_completion
{
    /* completion context */
    void *server;               /* server pointer                             */
    void *channel;              /* channel pointer                            */
    int context;                /* context: null, nick, command, cmd arg      */
    char *base_command;         /* command with arg to complete (can be NULL) */
    int base_command_arg;       /* # arg to complete (if context is cmd arg)  */
    int arg_is_nick;            /* argument is nick                           */
    char *base_word;            /* word to complete (when Tab was pressed)    */
    int base_word_pos;          /* beggining of base word                     */
    int position;               /* position where Tab was pressed             */
    char *args;                 /* command line args (including base word)    */
    
    /* for command argument completion */
    t_weelist *completion_list; /* data list for completion                   */
    t_weelist *last_completion; /* last data element for completion           */
    
    /* completion found */
    char *word_found;           /* word found (to replace base word)          */
    int position_replace;       /* position where word has to be replaced     */
    int diff_size;              /* size difference (< 0 = char(s) deleted)    */
    int diff_length;            /* length difference (<= diff_size)           */
};

extern void completion_init (t_completion *, void *, void *);
extern void completion_free (t_completion *);
extern void completion_search (t_completion *, char *, int, int);

#endif /* completion.h */

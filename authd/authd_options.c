/*
 * Copyright (C) 2002 Brent N. Chun <bnc@caltech.edu>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307, USA.
 */
#if HAVE_CONFIG_H
#include <config.h>
#endif /* HAVE_CONFIG_H */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <getopt.h>
#include "authd_options.h"

static void print_help(const char *argv0, const struct option *longopts)
{
	const char *p;
	const struct option *q;

	if ((p = strchr(argv0, '/')) == NULL)
		p = argv0;
	else
		p++;
    printf("Usage: %s [OPTIONS] ...\n"
           "       Run authd server.\n\n", p);
	for (q = longopts; q->name; q++)
		if (q->has_arg == no_argument)
			printf("     -%c  --%s\n", q->val, q->name);
		else
			printf("     -%c  --%s=v\n", q->val, q->name);
}

static void print_version()
{
    printf("authd %s\n\n", VERSION);
    printf("Copyright (C) 2002 Brent N. Chun\n");
    printf("This program is distributed in the hope that it will be useful,\n");
    printf("but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
    printf("MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU\n");
    printf("Library General Public License for more details.\n\n");
    printf("Written by Brent N. Chun <bnc@caltech.edu>\n");
}

void authd_options_init(authd_options *opts)
{
    opts->daemon = 0;
}

void authd_options_parse(authd_options *opts, int argc, char **argv)
{
    int c;
    extern char *optarg;
    static struct option long_options[] =
    {
        { "daemon", no_argument, NULL, 'd' },
        { "help", no_argument, NULL, 'h' },
        { "version", no_argument, NULL, 'V' },
        { 0, 0, 0, 0 }
    };

    while ((c = getopt_long (argc, argv, "dhV", long_options, 
                             (int *)0)) != EOF) {
        switch (c) {
        case 'd':
            opts->daemon = 1;
            break;
        case 'h':
            print_help(argv[0], long_options);
            exit(0);
        case 'V':
            print_version();
            exit(0);
        }
    }
}

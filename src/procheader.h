/*
 * Sylpheed -- a GTK+ based, lightweight, and fast e-mail client
 * Copyright (C) 1999-2004 Hiroyuki Yamamoto
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __PROCHEADER_H__
#define __PROCHEADER_H__

#include <glib.h>
#include <stdio.h>
#include <time.h>

#include "procmsg.h"

typedef struct _HeaderEntry	HeaderEntry;
typedef struct _Header		Header;

struct _HeaderEntry
{
	gchar	 *name;
	gchar	 *body;
	gboolean  unfold;
};

struct _Header
{
	gchar *name;
	gchar *body;
};

gint procheader_get_one_field		(gchar		*buf,
					 gint		 len,
					 FILE		*fp,
					 HeaderEntry	 hentry[]);
gchar *procheader_get_unfolded_line	(gchar		*buf,
					 gint		 len,
					 FILE		*fp);

GSList *procheader_get_header_list_from_file	(const gchar	*file);
GSList *procheader_get_header_list		(FILE		*fp);
GSList *procheader_add_header_list		(GSList		*hlist,
						 const gchar	*header_name,
						 const gchar	*body);
GSList *procheader_merge_header_list		(GSList		*hlist1,
						 GSList		*hlist2);
gint procheader_find_header_list		(GSList		*hlist,
						 const gchar	*header_name);
void procheader_header_list_destroy		(GSList		*hlist);

GPtrArray *procheader_get_header_array		(FILE		*fp);
GPtrArray *procheader_get_header_array_asis	(FILE		*fp);
void procheader_header_array_destroy		(GPtrArray	*harray);

void procheader_header_free			(Header		*header);

void procheader_get_header_fields	(FILE		*fp,
					 HeaderEntry	 hentry[]);
MsgInfo *procheader_parse_file		(const gchar	*file,
					 MsgFlags	 flags,
					 gboolean	 full);
MsgInfo *procheader_parse_str		(const gchar	*str,
					 MsgFlags	 flags,
					 gboolean	 full);
MsgInfo *procheader_parse_stream	(FILE		*fp,
					 MsgFlags	 flags,
					 gboolean	 full);

gchar *procheader_get_fromname		(const gchar	*str);

time_t procheader_date_parse		(gchar		*dest,
					 const gchar	*src,
					 gint		 len);
void procheader_date_get_localtime	(gchar		*dest,
					 gint		 len,
					 const time_t	 timer);

#endif /* __PROCHEADER_H__ */

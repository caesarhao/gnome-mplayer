/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * gnome-mplayer.h
 * Copyright (C) 2016 Jungle <caesarhao@gmail.com>
 * 
 * gnome-mplayer is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * gnome-mplayer is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GNOME_MPLAYER_
#define _GNOME_MPLAYER_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GNOME_MPLAYER_TYPE_APPLICATION             (gnome_mplayer_get_type ())
#define GNOME_MPLAYER_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GNOME_MPLAYER_TYPE_APPLICATION, Gnomemplayer))
#define GNOME_MPLAYER_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), GNOME_MPLAYER_TYPE_APPLICATION, GnomemplayerClass))
#define GNOME_MPLAYER_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GNOME_MPLAYER_TYPE_APPLICATION))
#define GNOME_MPLAYER_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), GNOME_MPLAYER_TYPE_APPLICATION))
#define GNOME_MPLAYER_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), GNOME_MPLAYER_TYPE_APPLICATION, GnomemplayerClass))

typedef struct _GnomemplayerClass GnomemplayerClass;
typedef struct _Gnomemplayer Gnomemplayer;
typedef struct _GnomemplayerPrivate GnomemplayerPrivate;

struct _GnomemplayerClass
{
	GtkApplicationClass parent_class;
};

struct _Gnomemplayer
{
	GtkApplication parent_instance;

	GnomemplayerPrivate *priv;

};

GType gnome_mplayer_get_type (void) G_GNUC_CONST;
Gnomemplayer *gnome_mplayer_new (void);

/* Callbacks */

G_END_DECLS

#endif /* _APPLICATION_H_ */


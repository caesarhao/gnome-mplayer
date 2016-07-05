/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * gnome-mplayer.c
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
#include "gnome-mplayer.h"

#include <glib/gi18n.h>



/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/ui/gnome_mplayer.ui" */
#define UI_FILE "src/gnome_mplayer.ui"
#define TOP_WINDOW "window"


G_DEFINE_TYPE (Gnomemplayer, gnome_mplayer, GTK_TYPE_APPLICATION);

/* ANJUTA: Macro GNOME_MPLAYER_APPLICATION gets Gnomemplayer - DO NOT REMOVE */
struct _GnomemplayerPrivate
{
	/* ANJUTA: Widgets declaration for gnome_mplayer.ui - DO NOT REMOVE */
};

/* Create a new window loading a file */
static void
gnome_mplayer_new_window (GApplication *app,
                           GFile        *file)
{
	GtkWidget *window;

	GtkBuilder *builder;
	GError* error = NULL;

	GnomemplayerPrivate *priv = GNOME_MPLAYER_APPLICATION(app)->priv;

	/* Load UI from file */
	builder = gtk_builder_new ();
	if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
	{
		g_critical ("Couldn't load builder file: %s", error->message);
		g_error_free (error);
	}

	/* Auto-connect signal handlers */
	gtk_builder_connect_signals (builder, app);

	/* Get the window object from the ui file */
	window = GTK_WIDGET (gtk_builder_get_object (builder, TOP_WINDOW));
        if (!window)
        {
		g_critical ("Widget \"%s\" is missing in file %s.",
				TOP_WINDOW,
				UI_FILE);
        }

	
	/* ANJUTA: Widgets initialization for gnome_mplayer.ui - DO NOT REMOVE */

	g_object_unref (builder);
	
	
	gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
	if (file != NULL)
	{
		/* TODO: Add code here to open the file in the new window */
	}

	gtk_widget_show_all (GTK_WIDGET (window));
}


/* GApplication implementation */
static void
gnome_mplayer_activate (GApplication *application)
{
	gnome_mplayer_new_window (application, NULL);
}

static void
gnome_mplayer_open (GApplication  *application,
                     GFile        **files,
                     gint           n_files,
                     const gchar   *hint)
{
	gint i;

	for (i = 0; i < n_files; i++)
		gnome_mplayer_new_window (application, files[i]);
}

static void
gnome_mplayer_init (Gnomemplayer *object)
{
	object->priv = G_TYPE_INSTANCE_GET_PRIVATE (object, GNOME_MPLAYER_TYPE_APPLICATION, GnomemplayerPrivate);
}

static void
gnome_mplayer_finalize (GObject *object)
{
	G_OBJECT_CLASS (gnome_mplayer_parent_class)->finalize (object);
}

static void
gnome_mplayer_class_init (GnomemplayerClass *klass)
{
	G_APPLICATION_CLASS (klass)->activate = gnome_mplayer_activate;
	G_APPLICATION_CLASS (klass)->open = gnome_mplayer_open;

	g_type_class_add_private (klass, sizeof (GnomemplayerPrivate));

	G_OBJECT_CLASS (klass)->finalize = gnome_mplayer_finalize;
}

Gnomemplayer *
gnome_mplayer_new (void)
{
	return g_object_new (gnome_mplayer_get_type (),
	                     "application-id", "org.gnome.gnome_mplayer",
	                     "flags", G_APPLICATION_HANDLES_OPEN,
	                     NULL);
}


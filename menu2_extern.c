#include <gtk/gtk.h>
#include <glib/gprintf.h>
#include <string.h>
 
 
/* Wird aus dem Menü aufgerufen */
G_MODULE_EXPORT void kleine_callback (GtkWidget *w, gpointer d)
{
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new (NULL,
        GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
        GTK_BUTTONS_CLOSE, "Hallo, Welt!");
    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
}
 
 
/* Wird aufgerufen, wenn ein Tag ausgewählt wurde. */
G_MODULE_EXPORT void tag_auswaehlen (GtkWidget *l, gpointer c)
{
    guint jahr, monat, tag;
    gchar text[32];
    GtkLabel *label = GTK_LABEL(l);
    GtkCalendar *calendar = GTK_CALENDAR(c);
    gtk_calendar_get_date (calendar, &jahr, &monat, &tag);
    g_snprintf (text, 32, "Ausgewählt: %02d.%02d.%d", tag, monat, jahr);
    gtk_label_set_text (label, text);
}
 
 
int main (int argc, char *argv[])
{
    GtkBuilder *builder;
    GError *errors = NULL;
    GtkWidget *window;
 
    gtk_init (&argc, &argv);
    builder = gtk_builder_new ();
    gtk_builder_add_from_file (builder, "menu2.xml", &errors);
    gtk_builder_connect_signals (builder, builder);
    window = GTK_WIDGET(gtk_builder_get_object (builder, "hauptfenster"));
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}

#include <gtk/gtk.h>
#include <glib/gprintf.h>
#include <string.h>
 
 
G_MODULE_EXPORT void fettschreiben (GtkWidget *t, gpointer d)
{
    GtkTextIter anfang, ende;
    GtkTextTag *fett;
    GtkTextTagTable *tag_tabelle;
 
    GtkTextView *textview = GTK_TEXT_VIEW(t);
    GtkTextBuffer *buffer = gtk_text_view_get_buffer (textview);
    /* Anfang und Ende vom Text */
    gtk_text_buffer_get_iter_at_offset (buffer, &anfang, 0);
    gtk_text_buffer_get_iter_at_offset (buffer, &ende, -1);
    /* Nachsehen, ob dieser tag schon gespeichert ist */
    tag_tabelle = gtk_text_buffer_get_tag_table (buffer);
    fett = gtk_text_tag_table_lookup (tag_tabelle, "fett_monospace");
    if (fett == NULL)
        /* sonst neu erstellen */
        fett = gtk_text_buffer_create_tag (buffer, "fett_monospace", "family", "Monospace", "weight", PANGO_WEIGHT_BOLD, NULL);
    /* tag anwenden */
    gtk_text_buffer_apply_tag (buffer, fett, &anfang, &ende);
}
 
 
int main (int argc, char *argv[])
{
    GtkBuilder *builder;
    GError *errors = NULL;
    GtkWidget *window;
 
    gtk_init (&argc, &argv);
    builder = gtk_builder_new ();
    gtk_builder_add_from_file (builder, "toolbar1.xml", &errors);
    gtk_builder_connect_signals (builder, builder);
    window = GTK_WIDGET(gtk_builder_get_object (builder, "hauptfenster"));
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}

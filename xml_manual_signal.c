#include <gtk/gtk.h>
#include <string.h>
 
static const gchar *interface =
    "<interface>"
    "  <object class=\"GtkWindow\" id=\"main-window\">"
    "    <child>"
    "      <object class=\"GtkButton\" id=\"my-button\">"
    "        <property name=\"label\">Hallo, Welt!</property>"
    "      </object>"
    "    </child>"
    "  </object>"
    "</interface>";
 
static void on_button_clicked (GtkWidget *w, gpointer d)
{
    g_print ("Hallo, Welt!\n");
}
 
int main (int argc, char *argv[])
{
    GtkBuilder *builder;
    GError *error = NULL;
    GtkWidget *window, *button;
 
    gtk_init (&argc, &argv);
    builder = gtk_builder_new ();
    gtk_builder_add_from_string (builder, interface, strlen (interface), &error);
    window = GTK_WIDGET(gtk_builder_get_object (builder, "main-window"));
    g_signal_connect (window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    button = GTK_WIDGET(gtk_builder_get_object (builder, "my-button"));
    g_signal_connect (button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}

#include <gtk/gtk.h>
 
static const gchar *interface = 
    "<interface>"
    "  <object class=\"GtkWindow\" id=\"main-window\">"
    "    <signal name=\"destroy\" handler=\"gtk_main_quit\"/>"
    "    <child>"
    "      <object class=\"GtkButton\" id=\"my-button\">"
    "        <property name=\"label\">Hallo, Welt!</property>"
    "        <signal name=\"clicked\" handler=\"on_button_clicked\"/>"
    "      </object>"
    "    </child>"
    "  </object>"
    "</interface>";
 
G_MODULE_EXPORT void on_button_clicked (GtkWidget *w, gpointer d)
{
    g_print ("Hallo, Welt!\n");
}
 
int main (int argc, char *argv[])
{
    GtkBuilder *builder;
    GError *error = NULL;
    GtkWidget *window;
 
    gtk_init (&argc, &argv);
    builder = gtk_builder_new ();
    gtk_builder_add_from_string (builder, interface, -1, &error);
    gtk_builder_connect_signals (builder, NULL);
    window = GTK_WIDGET(gtk_builder_get_object (builder, "main-window"));
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}

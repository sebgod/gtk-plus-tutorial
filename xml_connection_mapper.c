#include <gtk/gtk.h>
 
static const gchar *interface = 
    "<interface>"
    "  <object class=\"GtkWindow\" id=\"main-window\">"
    "    <signal name=\"destroy\" handler=\"gtk_main_quit\"/>"
    "    <child>"
    "      <object class=\"GtkButton\" id=\"my-button\">"
    "        <property name=\"label\">Hello World!</property>"
    "        <signal name=\"clicked\" handler=\"on_button_clicked\"/>"
    "      </object>"
    "    </child>"
    "  </object>"
    "</interface>";
 
static void on_button_clicked (GtkWidget *w, gpointer d)
{
    g_print ("Hallo, Welt!\n");
}
 
static void connection_mapper (GtkBuilder *builder, GObject *object,
	const gchar *signal_name, const gchar *handler_name,
	GObject *connect_object, GConnectFlags flags, gpointer user_data)
{
    g_print ("Connect %s with %s\n", signal_name, handler_name);
 
    if (g_strcmp0 (handler_name, "gtk_main_quit") == 0)
        g_signal_connect (object, signal_name, G_CALLBACK(gtk_main_quit), 0);
    else if (g_strcmp0 (handler_name, "on_button_clicked") == 0)
        g_signal_connect (object, signal_name, G_CALLBACK(on_button_clicked), 0);
    else
        g_print ("Unknown callback!\n");
}
 
int main (int argc, char *argv[])
{
    GtkBuilder *builder;
    GError *error = NULL;
    GtkWidget *window;
 
    gtk_init (&argc, &argv);
    builder = gtk_builder_new ();
    gtk_builder_add_from_string (builder, interface, -1, &error);
    gtk_builder_connect_signals_full (builder, connection_mapper, NULL);
    window = GTK_WIDGET(gtk_builder_get_object (builder, "main-window"));
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}

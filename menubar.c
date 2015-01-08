#include <gtk/gtk.h>
#include <glib/gprintf.h>
#include <string.h>
 
 
void kleine_callback (GtkWidget *w, gpointer d)
{
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new (NULL,
        GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
        GTK_BUTTONS_CLOSE, "Hallo, Welt!");
    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
}
 
static const gchar * interface = 
"<interface>"
"    <object class=\"GtkUIManager\" id=\"uimanager\">"
"    <child>"
"        <object class=\"GtkActionGroup\" id=\"aktionen\">"
"        <child>"
"            <object class=\"GtkAction\" id=\"datei\">"
"            <property name=\"label\">_Datei</property>"
"            </object>"
"        </child>"
"        <child>"
"            <object class=\"GtkAction\" id=\"neu\">"
"            <property name=\"label\">_Neue Datei</property>"
"            <signal name=\"activate\" handler=\"kleine_callback\"/>"
"            </object>"
"        </child>"
"        <child>"
"            <object class=\"GtkAction\" id=\"exit\">"
"            <property name=\"label\">_Beenden</property>"
"            <property name=\"stock-id\">gtk-quit</property>"
"            <signal name=\"activate\" handler=\"gtk_main_quit\"/>"
"            </object>"
"        </child>"
"        <child>"
"            <object class=\"GtkAction\" id=\"bearbeiten\">"
"            <property name=\"label\">_Bearbeiten</property>"
"            </object>"
"        </child>"
"        </object>"
"    </child>"
"    <ui>"
"    <menubar name=\"menubar\">"
"        <menu action=\"datei\" >"
"            <menuitem action=\"neu\" />"
"            <separator />"
"            <menuitem action=\"exit\" />"
"        </menu>"
"        <menu action=\"bearbeiten\" />"
"    </menubar>"
"    </ui>"
"    </object>"
"   "
"    <object class=\"GtkWindow\" id=\"main_window\" >"
"    <signal name=\"destroy\" handler=\"gtk_main_quit\"/>"
"    <child>"
"        <object class=\"GtkVBox\" id=\"vbox-layout\">"
"        <property name=\"homogeneous\">FALSE</property>"
"        <child>"
"       <object class=\"GtkMenuBar\" id=\"menubar\" constructor=\"uimanager\"/>"
"        </child>"
"        </object>"
"    </child>"
"    </object>"
"</interface>";
 
 
int main (int argc, char *argv[])
{
    GtkBuilder *builder;
    GError *errors = NULL;
    GtkWidget *window;
 
    gtk_init (&argc, &argv);
    builder = gtk_builder_new ();
    gtk_builder_add_from_string (builder, interface,
	strlen(interface), &errors);
    gtk_builder_connect_signals (builder, NULL);
    window = GTK_WIDGET(gtk_builder_get_object (builder, "main_window"));
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}


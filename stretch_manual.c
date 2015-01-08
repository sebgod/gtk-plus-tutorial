#include <gtk/gtk.h>
 
int main (int argc, char *argv[])
{
    GtkWidget *window, *hpanes, *buttons[2];
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
 
    hpanes = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
 
    buttons[0] = gtk_button_new_with_label ("erster");
    buttons[1] = gtk_button_new_with_label ("zweiter");
 
    gtk_paned_add1 (GTK_PANED(hpanes), buttons[0]);
    gtk_paned_add2 (GTK_PANED(hpanes), buttons[1]);
 
    gtk_container_add (GTK_CONTAINER(window), hpanes);
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}

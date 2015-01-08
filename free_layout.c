#include <gtk/gtk.h>
 
 
static void move_button (GtkWidget *button, GtkWidget *layout)
{
    gint x;
    gtk_container_child_get (GTK_CONTAINER(layout), button, "x", &x, NULL);
    x = x % 100 + 10;
    gtk_layout_move (GTK_LAYOUT(layout), button, x, 50);
}
 
int main (int argc, char *argv[])
{
    GtkWidget *window, *layout, *button, *label;
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
 
    layout = gtk_layout_new (NULL, NULL);
 
    label = gtk_label_new ("Test");
    button = gtk_button_new_with_label ("Drück mich!");
 
    gtk_layout_put (GTK_LAYOUT(layout), label, 10, 10);
    gtk_layout_put (GTK_LAYOUT(layout), button, 20, 100);
    g_signal_connect (button, "clicked", G_CALLBACK(move_button), layout);
 
    gtk_container_add (GTK_CONTAINER(window), layout);
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}

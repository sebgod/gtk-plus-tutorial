#include <gtk/gtk.h>
 
 
int main (int argc, char *argv[])
{
    GtkWidget *window, *vbox, *buttons[4];
 
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
 
    vbox = gtk_vbox_new (FALSE, 2);
 
    buttons[0] = gtk_button_new_with_label ("FALSE, FALSE");
    gtk_box_pack_start (GTK_BOX(vbox), buttons[0], FALSE, FALSE, 0);
    buttons[1] = gtk_button_new_with_label ("TRUE, FALSE");
    gtk_box_pack_start (GTK_BOX(vbox), buttons[1], TRUE, FALSE, 0);
    buttons[2] = gtk_button_new_with_label ("TRUE, TRUE");
    gtk_box_pack_start (GTK_BOX(vbox), buttons[2], TRUE, TRUE, 0);
    buttons[3] = gtk_button_new_with_label ("FALSE, TRUE");
    gtk_box_pack_start (GTK_BOX(vbox), buttons[3], FALSE, TRUE, 0);
 
    gtk_container_add (GTK_CONTAINER(window), vbox);
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}


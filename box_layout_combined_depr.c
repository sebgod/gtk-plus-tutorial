#include <gtk/gtk.h>
 
 
int main (int argc, char *argv[])
{
    GtkWidget *window, *hbox, *vbox, *buttons[5];
 
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
 
    vbox = gtk_vbox_new (FALSE, 0);
 
    /* Obere Zeile */
    buttons[0] = gtk_button_new_with_label ("Menü");
    gtk_box_pack_start (GTK_BOX(vbox), buttons[0], FALSE, FALSE, 0);
 
    /* Mittlerer Bereich */
    hbox = gtk_hbox_new (TRUE, 0);
    buttons[1] = gtk_button_new_with_label ("TRUE, TRUE");
    gtk_box_pack_start (GTK_BOX(hbox), buttons[1], TRUE, TRUE, 0);
    buttons[2] = gtk_button_new_with_label ("FALSE, FALSE");
    gtk_box_pack_start (GTK_BOX(hbox), buttons[2], FALSE, FALSE, 0);
    buttons[3] = gtk_button_new_with_label ("TRUE, TRUE");
    gtk_box_pack_start (GTK_BOX(hbox), buttons[3], TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
 
    /* Untere Zeile */
    buttons[4] = gtk_button_new_with_label ("Status");
    gtk_box_pack_start (GTK_BOX(vbox), buttons[4], FALSE, FALSE, 0);
 
    gtk_container_add (GTK_CONTAINER(window), vbox);
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}

#include <gtk/gtk.h>
 
int main (int argc, char *argv[])
{
#if GTK_MAJOR_VERSION >= 3
    GtkWidget *window, *hpanes, *vpanes, *buttons[3];
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
 
    /* Horizontale Stretchbereiche mit 2 Knöpfen */
    hpanes = gtk_paned_new (GTK_ORIENTATION_HORIZONTAL);
    buttons[0] = gtk_button_new_with_label ("erster");
    buttons[1] = gtk_button_new_with_label ("zweiter");
    gtk_paned_add1 (GTK_PANED(hpanes), buttons[0]);
    gtk_paned_add2 (GTK_PANED(hpanes), buttons[1]);
 
    /* Vertikaler Stretchbereich mit einem Knopf und obigem Bereich */
    vpanes = gtk_paned_new (GTK_ORIENTATION_VERTICAL);
    buttons[2] = gtk_button_new_with_label ("dritter");
    gtk_paned_add1 (GTK_PANED(vpanes), buttons[2]);
    gtk_paned_add2 (GTK_PANED(vpanes), hpanes);
 
    gtk_container_add (GTK_CONTAINER(window), vpanes);
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
#else
    fprintf(stderr, "GTK major version %d is not supported!\n", GTK_MAJOR_VERSION);
    return 1;
#endif
}

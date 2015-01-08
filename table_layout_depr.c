#include <gtk/gtk.h>
 
 
static void change_homogenous (GtkWidget *widget, GtkTable *table)
{
    /* Homogenität ändern */
    gtk_table_set_homogeneous (table, !gtk_table_get_homogeneous (table));
}
 
int main (int argc, char *argv[])
{
    GtkWidget *window, *table, *buttons[5], *labels[4];
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
 
    /* Tabelle mit 3 Reihen und 3 Spalten, uneinheitliche Größe */
    table = gtk_table_new (3, 3, FALSE);
 
    /* Knöpfe und Texte erstellen */
    buttons[0] = gtk_button_new_with_label ("0");
    buttons[1] = gtk_button_new_with_label ("rechts oben");
    buttons[2] = gtk_button_new_with_label ("homogen?");
    g_signal_connect (buttons[2], "clicked",
	G_CALLBACK(change_homogenous), table);
    buttons[3] = gtk_button_new_with_label ("0");
    buttons[4] = gtk_button_new_with_label ("rechts unten");
    labels[0] = gtk_label_new ("N");
    labels[1] = gtk_label_new ("W");
    labels[2] = gtk_label_new ("O");
    labels[3] = gtk_label_new ("S");
 
    /* erste Reihe */
    gtk_table_attach_defaults (GTK_TABLE(table), buttons[0], 0, 1, 0, 1);
    gtk_table_attach_defaults (GTK_TABLE(table), labels[0], 1, 2, 0, 1);
    gtk_table_attach_defaults (GTK_TABLE(table), buttons[1], 2, 3, 0, 1);
 
    /* zweite Reihe */
    gtk_table_attach_defaults (GTK_TABLE(table), labels[1], 0, 1, 1, 2);
    gtk_table_attach_defaults (GTK_TABLE(table), buttons[2], 1, 2, 1, 2);
    gtk_table_attach_defaults (GTK_TABLE(table), labels[2], 2, 3, 1, 2);
 
    /* dritte Reihe */
    gtk_table_attach_defaults (GTK_TABLE(table), buttons[3], 0, 1, 2, 3);
    gtk_table_attach_defaults (GTK_TABLE(table), labels[3], 1, 2, 2, 3);
    gtk_table_attach_defaults (GTK_TABLE(table), buttons[4], 2, 3, 2, 3);
 
    gtk_container_add (GTK_CONTAINER(window), table);
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}


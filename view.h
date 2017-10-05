#ifndef __VIEW_H
#define __VIEW_H 201609
 
#include "library.h"
#include "dialogs.h"

class View {
  public:
    View(Library& lib) : library(lib) { }
    int select_from_menu();
    int select_publication();
    int select_patron();
    void list_publications();
    void list_patrons();
    void show_error(string error);
    void help();

    // Add publication methods
    string get_title();
    string get_author();
    string get_copyright();
    int get_genre();
    int get_media();
    int get_age();
    string get_isbn();

    // Add patron methods
    string get_patron_name();
    string get_patron_phone_number();

  private:
    Library& library;
    string get_publications();
    string get_patrons();
};
#endif

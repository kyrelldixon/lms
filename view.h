#ifndef __VIEW_H
#define __VIEW_H 201609
 
#include "library.h"
#include "dialogs.h"

class View {
  public:
    View(Library& lib) : library(lib) { }
    int select_from_menu();
    void list_publications();
    void list_patrons();
    void help();
  private:
    Library& library; 
};
#endif

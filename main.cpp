#include "controller.h"
#include "library.h"

#include <gtkmm.h>

int main(int argc, char *argv[]) {
  Gtk::Main kit(argc, argv);
  
  Library library;
  Controller controller(library);
  controller.gui();
}

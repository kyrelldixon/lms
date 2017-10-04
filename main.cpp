#include "controller.h"
#include "library.h"

#include <gtkmm.h>
#include "dialogs.h"

int main(int argc, char *argv[]) {
  Gtk::Main kit(argc, argv);
  
  Library library;
  Controller controller(library);
  controller.cli();

  string title{"Hello, World"};
  string text;

  text = Dialogs::input("This is me saying hello. ", title);
  if (text == "CANCEL") return 0;
}

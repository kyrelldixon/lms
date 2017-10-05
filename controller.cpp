#include "controller.h"
#include "view.h"
#include "library.h"
#include "publication.h"
#include "patron.h"
#include "genre.h"
#include "media.h"
#include "age.h"
#include <iostream>
#include <string>

using namespace std;

void Controller::gui() {
  int cmd = -1;
  while (cmd != 0) {
    cmd = view.select_from_menu();
    execute_cmd(cmd);
  }
}

void Controller::execute_cmd(int cmd) {
  if (cmd == 1) { // Add publication
    string title, author, copyright, isbn;
    int genre, media, age;

    title = view.get_title();
    author = view.get_author();
    copyright = view.get_copyright();
    genre = view.get_genre();
    media = view.get_media();
    age = view.get_age();
    isbn = view.get_isbn();

    library.add_publication(Publication(title, author, copyright, genre, media, age, isbn));

 } else if (cmd == 2) { // List all publications
    view.list_publications();

 } else if (cmd == 3) { // Check out publication
    if (library.number_of_publications() == 0) {
      view.show_error("There are currently no publications");
      return;
    }
  
    int pub = view.select_publication();
    int pat = view.select_patron();

    try {
      library.check_out(pub, pat);
    } catch (Publication::Invalid_transaction e) {
      cerr << "ERROR: That publication is already checked out!" << endl;
    }

    
    
 } else if (cmd == 4) { // Check in publication
    if (library.number_of_publications() == 0) {
      view.show_error("There are currently no publications");
      return;
    }
  
    int pub = view.select_publication();

    try {
      library.check_in(pub);
    } catch (Publication::Invalid_transaction e) {
      cerr << "ERROR: That publication is already checked in!" << endl;
    }

 } else if (cmd == 5) { // Add patron
    string name, number;

    name = view.get_patron_name();
    number = view.get_patron_phone_number();
    library.add_patron(Patron(name, number));
    
 } else if (cmd == 6) { // List all patrons
    view.list_patrons();

 } else if (cmd == 9) { // Help
    view.help();
 } else if (cmd == 0) { // Exit
 } else if (cmd == 99) { // Easter Egg
   library.easter_egg();
 } else {
   cerr << "**** Invalid command - type 9 for help" << endl << endl;
 }
}


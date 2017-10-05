#include "view.h"
#include <iostream>
#include <string>

using namespace std;

int View::select_from_menu() {
  string text;    // Temp for holding user's input
  int guess = 0;
  string title = "Main Menu";
  string menu = R"(
=================================
CSE1325 Library Management System
=================================

Publications
------------
(1) Add publication
(2) List all publications
(3) Check out publication
(4) Check in publication

Patrons
=======
(5) Add patron
(6) List all patrons

Utility
-------
(9) Help
(0) Exit

)";

  text = Dialogs::input(menu, title);
  if (text == "CANCEL") return guess;

  guess = atoi(text.c_str());

  return guess;
}

void View::list_publications() {
  string title = "List of Library Publications";
  string msg = get_publications();

  Dialogs::message(msg, title);
}


void View::list_patrons() {
  string title = "List of Beloved Patrons";
  string msg = get_patrons();

  Dialogs::message(msg, title);
}

void View::help() {
  string title = "Help";
  string helptext = R"(
The LMS tracks publication assets for a library, including those who
check out and return those publications.

(1) Add publication - This allows the librarian to enter data
    associated with a new publication.
(2) List all publications - All data known about each publication
    in the library is listed.
(3) Check out publication - Enter the data for patrons who check out
    a publication, and mark that publication as checked out.
(4) Check in publication - Select a publication and mark it as checked in.
(5) Add patron - This allows the librarian to enter data associated
    with a new library patron.
(6) List patrons - All data know about each patron of the library.
(9) Help - Print this text.
(0) Exit - Exit the program. WARNING: The current version does NOT
    save any entered data. This feature will be added in the "next version".

Use the '99' command to pre-populate test data.
  )";
  Dialogs::message(helptext, title);
}

string View::get_publications() {
  string publications{""};
  
  for (int i=0; i<library.number_of_publications(); ++i) {
    publications += to_string(i) + ") " + library.publication_to_string(i) + "\n";
  }

  return publications;
}

string View::get_patrons() {
  string patrons{""};
  
  for (int i=0; i<library.number_of_patrons(); ++i) {
    patrons += to_string(i) + ") " + library.patron_to_string(i) + "\n";
  }

  return patrons;
}

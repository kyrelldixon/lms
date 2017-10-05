#include "view.h"
#include <iostream>
#include <string>

using namespace std;

int View::select_from_menu() {
  string text;    // Temp for holding user's input
  int choice = 0;
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
  if (text == "CANCEL") return choice;

  choice = atoi(text.c_str());

  return choice;
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

int View::select_publication() {
  string title = "Add Publication";
  string msg = get_publications();
  string text;
  int choice = 0;

  text = Dialogs::input(msg, title);

  if (text == "CANCEL") return choice;
  
  choice = atoi(text.c_str());
  
  return choice;
}

int View::select_patron() {
  string title = "Add Patron";
  string msg = get_patrons();
  string text;
  int choice = 0;

  text = Dialogs::input(msg, title);

  if (text == "CANCEL") return choice;
  
  choice = atoi(text.c_str());
  
  return choice;
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

// Add publication methods

string View::get_title() {
  string dialog_title = "Title";
  string msg = "Enter Title";
  string title;

  title = Dialogs::input(msg, dialog_title);

  return title;
}

string View::get_author() {
  string dialog_title = "Author";
  string msg = "Enter Author";
  string author;

  author = Dialogs::input(msg, dialog_title);

  return author;
}

string View::get_copyright() {
  string dialog_title = "Copyright";
  string msg = "Enter Copyright Year";
  string copyright;

  copyright = Dialogs::input(msg, dialog_title);

  return copyright;
}

string View::get_isbn() {
  string dialog_title = "Title";
  string msg = "Enter ISBN";
  string isbn;

  isbn = Dialogs::input(msg, dialog_title);

  return isbn;
}

// Add patron methods

string View::get_patron_name() {
  string dialog_title = "Name";
  string msg = "Enter Name";
  string name;

  name = Dialogs::input(msg, dialog_title);

  return name;
}

string View::get_patron_phone_number() {
  string dialog_title = "Phone Number";
  string msg = "Enter Phone Number";
  string number;

  number = Dialogs::input(msg, dialog_title);

  return number;
}
#include "view.h"
#include "patron.h"
#include "publication.h"
#include "library.h"
#include <iostream>
using namespace std;

int main() {
  Library library;
  View view(library);

  bool passed = true;

  //
  // Set up library
  //
  Patron larry("Larry", "817-555-1111");
  Patron curly("Curly", "817-555-2222");
  Patron moe("Moe", "817-555-3333");

  library.add_patron(larry);
  library.add_patron(curly);
  library.add_patron(moe);

  Publication foundation("Foundation", "Isaac Asimov", "1942", 
      Genre::fiction, Media::book, Age::adult, "0385177259");
  Publication foundation_empire("Foundation and Empire", "Isaac Asimov", "1943", 
      Genre::fiction, Media::book, Age::adult, "0385177259");
  Publication foundation2("Second Foundation", "Isaac Asimov", "1944", 
      Genre::fiction, Media::book, Age::adult, "0385177259");
  Publication war("War of the Worlds", "Jeff Wayne", "1977",
      Genre::performance, Media::audio, Age::teen, "9780711969148");
  Publication wonka("Willy Wonka and the Chocolate Factory", "Roald Dahl", "1971",
      Genre::performance, Media::video, Age::children, "0142410314");

  library.add_publication(foundation);
  library.add_publication(foundation_empire);
  library.add_publication(foundation2);
  library.add_publication(war);
  library.add_publication(wonka);

  library.check_out(2, 1);

  //
  // Test menu
  //
  cout << endl;
  view.show_menu();

  //
  // Test list publications
  //
  cout << endl;
  view.list_publications();

  //
  // Test list patrons
  //
  cout << endl;
  view.list_patrons();

  //
  // Show results
  //
  cout << endl << "Verify output for pass or fail" << endl;
}

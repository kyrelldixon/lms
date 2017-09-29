#include "controller.h"
#include "library.h"

int main() {
  Library library;
  Controller controller(library);
  controller.cli();
}

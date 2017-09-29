 #include "publication.h"
 #include <string>
 #include <iostream>

 using namespace std;


 bool Publication::is_checked_out() {return checked_out;}
 void Publication::check_out(Patron& p_patron) {
   if (checked_out) {
     throw Invalid_transaction();
   } else {
     patron = p_patron;
     checked_out = true;
   }
 }
   
 void Publication::check_in() {
   if (checked_out) {
     checked_out = false;
   } else {
     throw Invalid_transaction();
   }
 }

 string Publication::to_string() {
   string pub = "\"" + title + "\"" + " by " + author + ", " + copyright + 
     " (" + target_age.to_string() + " " + genre.to_string() + " "  
         + media.to_string() + ") " + "ISBN: " + isbn;
   if (checked_out) {
      pub += "\nChecked out to " + patron.get_patron_name() + 
             " (" + patron.get_patron_phone_number() + ")";
   }
   return pub;
 }

#include "Mystring.h"

int main(){
    Mystring empty;
    Mystring larry{"Larry"};
    Mystring stooge{larry};

    empty = larry;

    Mystring josh{"Josh"};

    josh = Mystring{"Joshua"};

    empty.display();
    larry.display();
    stooge.display();
    josh.display();

    return 0;
}
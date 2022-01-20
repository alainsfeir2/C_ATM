
#include <iostream>
#include <string>
#include <fstream>

#include <F:\Programming\Coding\C++\Atm\C_ATM\Lib\Login.h>

using namespace std ;

int main() {
    bool access = false;
    while (!access){
        access = sign_in(access);
    }
}
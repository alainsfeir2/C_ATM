
#include <iostream>
#include <string>
#include <fstream>

#include <F:\Programming\Coding\C++\Atm\C_ATM\Lib\Login.h>

using namespace std ;


int check_balance(string user);
void add_balance(string user);
void remove_balance(string user);
void sign_out(string user);
void sign_in(string user);

int main() {
    bool access = false;
    while (!access){
        access = sign_in(access);
    }
}
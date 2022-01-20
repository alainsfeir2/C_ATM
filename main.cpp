
#include <iostream>
#include <string>
#include <fstream>

#include <F:\Programming\Coding\C++\Atm\C_ATM\Lib\Login.h>

using namespace std ;

int main() {
    //struct user_data user_1 ;
    int state = 0;
    while (true){
        struct user_data user_1 ;
        switch (state){
            case 0:
                while (!(user_1.access)){
                    user_1 = sign_in(user_1);
                    state = 0;
                    }
                state = 1;
                cout<<"Access Granted"<<endl;
                break;

            case 1:
                cout<<"Welcome "+user_1.username+" !"<<endl;
                string option;
                do{
                    cout<<"1.Check Balance\n2.Deposit\n3.Logout"<<endl;
                    cin>> option;
                    if (option == "1"){
                        cout<<"Your Balance " + to_string(user_1.balance) <<endl;
                        state =1;
                    }
                    else if (option == "3"){
                        state=0;
                        break;
                    }
                }
                while (option != "3");
                
        }
    }
    
}
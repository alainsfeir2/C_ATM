#include <iostream>
#include <string>
#include <fstream>

using namespace std ;
struct user_data {
            string username;
            string password;
            float balance;
            bool access = false;
        };

struct user_data sign_in(struct user_data user_1){
        
        string username;
        string password;
        cout<<"Enter username:"<< endl;
        cin>>username;
        cout<<"Enter password:"<< endl;
        cin>>password;
        //Login verification
        string user_info[100][100];

        ifstream users ( "Users/users.txt" );

        if (!users)
        {
            cout << "There was an error opening the file.\n";
            return user_1;
        }
        else{
            string line;
            int row = 0;
            int col = 0;

            if (users.is_open())
            {

                while ( getline (users,line) ){
                        int i=0;
                        while (line[i] != ':'){
                            string word = user_info[row][col];
                            word= word + line[i];
                            user_info[row][col]=word ;
                            i = i+1;
                            if (line[i] == ':'){
                                
                                col++;
                                i++;
                                
                            }
                            if (line[i] == '#'){
                                row++;
                                col=0;
                                break;
                            }
                        }
                            
                    }
                    users.close();
            }
            bool found;
            string comp_pass;
            string balance;
            for(int i=0;i<100;i++){
                
                if(user_info[i][0] == username){
                    comp_pass = user_info[i][1];
                    balance = user_info[i][2];
                    found = true;
                    break;
                    }
                }
            user_1.balance = stof(balance);
            user_1.password = comp_pass;
            user_1.username = username;
            user_1.access = found ;

            if (found == false){
                cout<<"Username not found!"<<endl;
                user_1.access = false;
                return user_1;
            }else if(comp_pass != password){
                cout<<"Password wrong!"<<endl;
                user_1.access = false;
                return user_1;
            }else{
                user_1.access = true;
                return user_1;
            }   

        }
}
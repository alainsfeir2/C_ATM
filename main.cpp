
#include <iostream>
#include <string>
#include <fstream>

using namespace std ;

int check_balance(string user);
void add_balance(string user);
void remove_balance(string user);
void sign_out(string user);
void sign_in(string user);

int main() {
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
        return 0;
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
           for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout<<"\t"<<user_info[i][j];
                    }
                cout<<endl;
            }
            users.close();
        }

    }
    return 0;
}
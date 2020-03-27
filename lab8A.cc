#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

double decryptTheFile(double &key, ifstream &inStream, ofstream &outStream);
bool encryptTheFile(double &key, ifstream &inStream, ofstream &outStream);
bool obtainKeyValue(double &key);
bool displayMenu(double &key);
int main(int argc, char const *argv[]){

    int choice;
    double key;
    key = 3; //default

    do{

        displayMenu(key);                          // call the displayMenu function to display the menu
        cout << "-Enter in a value from top to bottom unless you wish to quit the program. :";
        cin >> choice;

    if(choice == 1){                            // call the set key function and assign to key

        cout << obtainKeyValue(key) << endl;

    }else if (choice == 2){                    //call the encryption function

        ifstream inStream;
        ofstream outStream;
        inStream.open("data.txt");
        outStream.open("output.txt");

        if(inStream.fail() || outStream.fail()){

            cout << "-There is an error opening the input or output of the file." << endl;
            exit(0);
        }
        encryptTheFile(key, inStream, outStream);
        cout << "*The file is now encrypted" << endl;
        

    }else if (choice == 3){                                 //call the decryption function

        ifstream inStream;
        ofstream outStream;
        inStream.open("output.txt");
        outStream.open("output2.txt");

        if(inStream.fail() || outStream.fail()){

            cout << "-There is an error opening the input or output of the file." << endl;
            
        }
        decryptTheFile(key, inStream, outStream);
    

    }
    }while(choice != 4);



 return 0;
}


bool displayMenu(double &key){

    cout << "1. -Set the shift key value (default is 3)" << endl;
    cout << "*The shift key is set to move " << key << " to the right*" << endl;
    cout << "2. -Encrypt a file" << endl;
    cout << "3. -Decrypt a file" << endl;
    cout << "4. -Quit" << endl;

return 'X';
}

bool obtainKeyValue(double &key){

    double keyLine = 0;
    cout << "-Enter a shift key value between 1 and 10 to Encrypt and Decrypt: ";
    cin >> keyLine;
    key = keyLine;

    return key;
}

bool encryptTheFile(double &key, ifstream &inStream, ofstream &outStream){

    char ch;
    int length = 0;
    string FileName;
    string FileName2;

    cout << "-Please enter an input file name: ";
    cin >> FileName;
    cout << endl;
    cout << "-Please enter an output file name: ";
    cin >> FileName2;
    cout << endl;

    while(inStream.eof() == 0){
        length++;
        inStream >> ch;
        ch = ch + key;
        outStream << ch;
    }
    return ch;

}

double decryptTheFile(double &key, ifstream &inStream, ofstream &outStream){

    char why;
    int length = 0;
    string FileName3;
    string FileName4;

    cout << "-Please enter an input file name: ";
    cin >> FileName3;
    cout << endl;
    cout << "-Please enter an output file name: ";
    cin >> FileName4;
    cout << endl;

    while(inStream.eof() == 0){
        length++;
        inStream >> why;
        why = why - key;
        outStream << why;
    }
    return why;

}

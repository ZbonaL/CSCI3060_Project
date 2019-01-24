#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main(int argc, char const *argv[]){
    
    /*
    TODO:
    take in file through args
    scan the file 
    print out file contents
    */
   ifstream inFile;
   string data;
   inFile.open(argv[1]);

   while(getline(inFile, data)){
       if(data == "login"){
           cout << "user is logged in." << endl;
           
       }
   }

   inFile.close();
   return 0;
}

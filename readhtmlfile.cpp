#include <sstream>
#include <fstream>
#include "readhtmlfile.h"
#include <string>
#include <iostream>

using namespace std;

string htmlcontent(const string &fullpath){
    ifstream file(fullpath);

    if(!file){
    
        cerr << "Unable to open file" << endl;
    };
    stringstream buffer;
    buffer << file.rdbuf();


    return buffer.str();


};



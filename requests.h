#ifndef REQUESTS_H
#define REQUESTS_H

#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>


using namespace std;

struct Requestobj{
    
        string method;
        string url;
        string body;

      
};


Requestobj req;
using functionType = function<void(Requestobj&)>;
unordered_map<string, functionType> setmain;


void setRequest(const string &buffer){
        



    
        string line;
            
        istringstream stream(buffer);
        if(getline(stream , line)) {
          
            istringstream firstline(line);
            firstline >> req.method >> req.url;
            

            
        };
    
    
            
};

void GET(const string &url , void (*func)(Requestobj&)) {
    
    
    
    
    setmain.insert({url , func});
    
     
            
       
}

#endif

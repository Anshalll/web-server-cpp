#ifndef REQUESTS_H
#define REQUESTS_H

#include <iostream>
#include <sstream>
#include <string>


using namespace std;

struct Requestobj{
        string method;
        string url;
        string body;

      
};


Requestobj setRequest(const string &buffer){
        

        Requestobj req;
        string line;
            
        istringstream stream(buffer);
        if(getline(stream , line)) {
          
            istringstream firstline(line);
            firstline >> req.method >> req.url;


            
        };
    

            
        return req;
};

#endif

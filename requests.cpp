#include "requests.h"
#include <unordered_map>
#include <sstream>


using namespace std;

Requestobj req;


unordered_map<string, function<void(Requestobj&)>> setget;
unordered_map<string, function<void(Requestobj&)>> setpost;

void setRequest(const string &buffer){
        
        string line;
        istringstream stream(buffer);
        if(getline(stream , line)) {
          
            istringstream firstline(line);
            firstline >> req.method >> req.url;

        };

        size_t bodyStart = buffer.find("\r\n\r\n");
        if (bodyStart != string::npos) {
            bodyStart+=4;
            string bodyobject = buffer.substr(bodyStart);
            req.body = bodyobject;

        };
};

void GET(const string& url, void (*handler)(Requestobj&)) {
    setget[url] = handler;
};

void POST(const string& url, void (*handler)(Requestobj&)) {
    setpost[url] = handler;
};



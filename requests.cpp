#include "requests.h"
#include <unordered_map>
#include <sstream>


using namespace std;

Requestobj req;


unordered_map<string, function<void(Requestobj&)>> setget;
unordered_map<string, function<void(Requestobj&)>> setpost;
unordered_map<string, function<void(Requestobj&)>> setput;
unordered_map<string, function<void(Requestobj&)>> setpatch;
unordered_map<string, function<void(Requestobj&)>> setdelete;


void setRequest(const string &buffer){
        
        string line;
        istringstream stream(buffer);
        if(getline(stream , line)) {
          
            istringstream firstline(line);
            firstline >> req.method >> req.url;

        };
            
};

void GET(const string& url, void (*handler)(Requestobj&)) {
    setget[url] = handler;
};

void POST(const string& url, void (*handler)(Requestobj&)) {
    setpost[url] = handler;
};

void PUT(const string& url, void (*handler)(Requestobj&)) {
    setput[url] = handler;
};

void PATCH(const string& url, void (*handler)(Requestobj&)) {
    setpatch[url] = handler;
};

void DELETE(const string& url, void (*handler)(Requestobj&)) {
    setdelete[url] = handler;
};


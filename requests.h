#ifndef REQUESTS_H
#define REQUESTS_H

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Requestobj {
    string method;
    string url;
    string body;
};

extern Requestobj req;

using functionType = function<void(Requestobj&)>;

extern unordered_map<string, functionType> setget;
extern unordered_map<string , functionType> setpost;
extern unordered_map<string , functionType> setpatch;
extern unordered_map<string , functionType> setput;
extern unordered_map<string , functionType> setdelete;


void setRequest(const string &buffer);
void GET(const string &url, void (*func)(Requestobj&));
void POST(const string &url, void (*func)(Requestobj&));
void PUT(const string &url, void (*func)(Requestobj&));
void PATCH(const string &url, void (*func)(Requestobj&));
void DELETE(const string &url, void (*func)(Requestobj&));

#endif  


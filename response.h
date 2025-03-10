#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>
#include <sys/socket.h> 
#include <cstring>

using namespace std;

struct client {
    int client_socket;
};

// Declare the global clientStruct
extern client clientStruct;

// Function Declarations
string responseString(size_t length, const string &content, const string &contentType);
void SendJson(const char *contents);
void SendHTML(const string &path);
#endif


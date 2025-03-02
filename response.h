#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>
#include <sys/socket.h>
#include <cstring>

using namespace std;

    struct client{
    
        int client_socket;
    } clientStruct;

    

    string responsestring(size_t length , const string &content, string &contentType) {
           // Send response
            string response = 
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: " + contentType + "\r\n"
                "Content-Length: " + to_string(length) + "\r\n"
                "\r\n" + 
                content;  

            return response;
    };

    void SendJson(const char *contents){

        string type = "application/json";

        string response = responsestring(strlen(contents) , string(contents) ,  type);

        send(clientStruct.client_socket, response.c_str(), response.length(), 0);
                  
        
    };



#endif


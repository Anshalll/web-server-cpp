#include "response.h"
#include "readhtmlfile.h"
#include <cstring>
#include <string>

client clientStruct;  // Define the global clientStruct
using namespace std;

// Define responseString
string responseString(size_t length, const string &content, const string &contentType) {
    string response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: " + contentType + "\r\n"
        "Content-Length: " + to_string(length) + "\r\n"
        "\r\n" +
        content;

    return response;
}

// Define SendJson
void SendJson(const char *contents) {
    string type = "application/json";
    string response = responseString(strlen(contents), string(contents), type);

    send(clientStruct.client_socket, response.c_str(), response.length(), 0);
};


void SendHTML(const string &path){
    
    
    string type = "text/html"; 
    string basepath = "templates/" + path;
    
    string content = htmlcontent(basepath);
    string response = responseString(content.length() , string(content) , type);

    send(clientStruct.client_socket , response.c_str() , response.length() , 0);

};

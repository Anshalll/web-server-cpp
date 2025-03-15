#ifndef SERVER_H
#define SERVER_H



#include <iostream>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <unistd.h> 
#include <cstdlib>
#include <cstring>
#include "requests.h"
#include "response.h"


using namespace std;

#define PORT 8080
#define BUFFER_SIZE 1024




class Server{

    public:   
        
        int server_fd;
        struct sockaddr_in address;
        int addrlen = sizeof(address);
        char buffer[BUFFER_SIZE] = {0};
        
    int CreateServer(){
    
            server_fd = socket(AF_INET , SOCK_STREAM, 0);
            if (server_fd == -1){
                return 1;
            };
            return 0;
    };

    Server(){
            address.sin_family = AF_INET; //IPV4 
            address.sin_port = htons(PORT); //Server listens on this port and htons for Converting to network byte order
            address.sin_addr.s_addr = INADDR_ANY; //Accept connections from all intefaces wifi , loopback or ethernet.
            
            if(CreateServer() == 1){
                cerr << "Failed to create socket\n";
                exit(1);
            }
            else{
                if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
                    cerr << "Binding failed\n";
                    exit(1);
                };
            };
            
            // Start listening (max 3 clients in queue)
            if (listen(server_fd, 3) < 0) {
                perror("Listen failed");
                exit(1);
            };            
            
            cout << "Listening on port " << PORT << endl;

    };

    void Run(){
        while (true){
            
            clientStruct.client_socket = accept(server_fd , (struct sockaddr*)&address , (socklen_t*)&addrlen);
            
            if(clientStruct.client_socket < 0){
                    
                cerr << "Accept failed\n";
                exit(1);
            };
                

            // Read http request
            
            read(clientStruct.client_socket , buffer,  BUFFER_SIZE);
            cout << "Received request: \n" << buffer << endl;
            
           

            
            setRequest(buffer);
                
            if(req.method == "GET") {
             for(const auto &pair : setget) {
                
                if(pair.first == req.url)
                {
                    pair.second(req);
                    

                };
            };

            }
            else if(req.method == "POST"){
               for(const auto &pair : setpost) {
                
                if(pair.first == req.url)
                {
                    pair.second(req);
                    

                };
            }; 
            }
            else if(req.method == "PUT"){
                for(const auto &pair : setput) {
                
                if(pair.first == req.url)
                {
                    pair.second(req);
                    

                };
             }; 
 
            }
            else if(req.method == "PATCH"){
           
               for(const auto &pair : setpatch) {
                
                if(pair.first == req.url)
                {
                    pair.second(req);
                    

                };
             }; 
 
            }
            else if(req.method == "DELETE"){
               
               for(const auto &pair : setdel) {
                
                if(pair.first == req.url)
                {
                    pair.second(req);
                    

                };
             }; 
 
            }
            else{
                cout << "Method not allowed";
            };


                   
            // Close connection
            close(clientStruct.client_socket);

        };
    };
};



#endif

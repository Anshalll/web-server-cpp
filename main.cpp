#include <iostream>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <unistd.h> 
#include <cstdlib>

using namespace std;



class Server{
    public:     
        int PORT = 8080; 
        int server_fd, client_socket;
        struct sockaddr_in address;
    
    int CreateServer(){
    
            server_fd = socket(AF_INET , SOCK_STREAM, 0);
            if (server_fd == -1){
                return 1;
            };
            return 0;
    };

    Server(){
            address.sin_family = AF_INET; //IPV4 
            address.sin_port = htons(PORT); //Server listens on this port and htons for Convert to network byte order
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
            
            
    };
    
    

};

int main(int argc , char *argv[]){
    
    Server main;


    

    return 0;
}

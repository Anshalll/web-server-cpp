#include <iostream>
#include "server.h"
#include "requests.h"

using namespace std;


void Index(Requestobj& req) {

    cout << "This is index page " <<  req.url << endl;
    
};

void Hello(Requestobj& req){
    

    cout << "This is Hello page" << req.url << endl;
        
};

int main() {
    

    Server app;

    GET("/home" , Index);
    GET("/hello" , Hello);
    
    app.Run();

    return 0;
}

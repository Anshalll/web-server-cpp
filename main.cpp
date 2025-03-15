#include "requests.h"
#include "response.h"
#include "server.h"


using namespace std;


void Index(Requestobj& req) {

    SendJson(R"({"message": "This is index page"})");    


};

void Hello(Requestobj& req){
    
    SendHTML("index.html");

    
};

void Register(Requestobj& req){
    SendText("<h1>This is my web server</h1>");

};

int main() {
    

    Server app;

    GET("/home" , Index);
    GET("/hello" , Hello);
    GET("/register" , Register); 
    app.Run();

    return 0;
}

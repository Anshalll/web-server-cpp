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

int main() {
    

    Server app;

    GET("/home" , Index);
    GET("/hello" , Hello);
    
    app.Run();

    return 0;
}

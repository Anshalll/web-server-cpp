#include "server.h"
#include "requests.h"
#include "response.h"



using namespace std;


void Index(Requestobj& req) {

    SendJson(R"({"message": "This is index page"})");    


};

void Hello(Requestobj& req){
    

       SendJson(R"({"message": "This is hello page"})");
};

int main() {
    

    Server app;

    GET("/home" , Index);
    GET("/hello" , Hello);
    
    app.Run();

    return 0;
}

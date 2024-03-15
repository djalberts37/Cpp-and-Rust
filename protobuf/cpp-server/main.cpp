#include <iostream>
#include "proto/helloworld.pb.h"
#include "proto/helloworld.grpc.pb.h"
#include <grpc/grpc.h>
#include <grpcpp/grpcpp.h> 
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>

using namespace std;
using namespace grpc;
using namespace helloworld;

class MyGreeter final : public Greeter::Service 
{
    Status SayHello(ServerContext* context, const HelloRequest* request, HelloReply* reply) override {
        cout << "Got a request: " << request->name() << endl;
        string message = "Hello " + request->name() + "!";
        reply->set_message(message);
        return Status::OK;
    }
};

void RunServer() 
{
    string server_address("localhost:50051");
    MyGreeter service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    unique_ptr<Server> server(builder.BuildAndStart());
    cout << "Server listening on " << server_address << endl;
    server->Wait();
}

int main() 
{
    RunServer();
    return 0;
}

#include <iostream>
#include "proto/helloworld.pb.h"
#include "proto/helloworld.grpc.pb.h"
#include <grpc/grpc.h> 
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>

using namespace std;
using namespace grpc;
using namespace helloworld;

void RunClient() 
{
    auto channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    auto client = Greeter::NewStub(channel);

    HelloRequest request;
    HelloReply reply;
    ClientContext context;
    request.set_name("True Legends from C++!");

    client->SayHello(&context, request, &reply);

    cout << "RESPONSE={" << reply.message() << "}" << endl;
}

int main() 
{
    RunClient();
    return 0;
}
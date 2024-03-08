#include <iostream>
#include "proto/helloworld.pb.h"
#include <grpc/grpc.h> 
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>

using namespace std;
using namespace grpc;

int main() {
    std::cout << "Hello World" << std::endl;

    grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials())
    unique_ptr<gRPCService::Stub> stub = gRPCService::NewStub(channel);

    helloworld::HelloRequest request;
    request.setName("True Legends from C++!");





}
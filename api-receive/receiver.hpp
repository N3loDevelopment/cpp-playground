#pragma once
#include <httplib.h>
#include <string>
#include <thread>
#include <iostream>

class Server
{
private:
    std::thread serverThread;
    httplib::Server server;

public:
    Server();
    ~Server();
    void getFiles(const std::string &filename, httplib::Response &res);
    void uploadFile(const httplib::Request &req, httplib::Response &res);
};
#include "receiver.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

Server::Server()
{
    serverThread = std::thread([this]()
                               {
        const int PORT = 8080;

        server.new_task_queue = [] { return new httplib::ThreadPool(4); };

        server.Get("/", [](const httplib::Request &, httplib::Response &res) {
            res.set_content("Server is running!", "text/plain");
        });

        server.Get("/getFiles/(.*)", [this](const httplib::Request &req, httplib::Response &res) {
            std::string filename = req.matches[1];
            getFiles(filename, res);
        });

        server.Post("/upload", [this](const httplib::Request &req, httplib::Response &res) {
            uploadFile(req, res);
        });

        std::cout << "Server running on Port: " << PORT << std::endl;
        server.listen("0.0.0.0", PORT); });
}

Server::~Server()
{
    server.stop();
    if (serverThread.joinable())
    {
        serverThread.join();
    }
}

void Server::getFiles(const std::string &filename, httplib::Response &res)
{
    std::ifstream file("../../uploads/" + filename, std::ios::binary);
    if (!file)
    {
        res.status = 404;
        res.set_content("File not found: " + filename, "text/plain");
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    res.set_content(buffer.str(), "application/octet-stream");
    res.set_header("Content-Disposition", "attachment; filename=" + filename);

    std::cout << "File sent: " << filename << std::endl;
}

void Server::uploadFile(const httplib::Request &req, httplib::Response &res)
{

    if (req.body.empty())
    {
        if (req.body.size() == 0)
            std::cout << "File cannot be empty." << std::endl;
        res.status = 400;
        res.set_content("No file uploaded", "text/plain");
        return;
    }

    std::string filename;

    if (req.has_header("X-Filename"))
        filename = req.get_header_value("X-Filename");
    else if (req.has_header("x-filename"))
        filename = req.get_header_value("x-filename");
    else
    {
        res.status = 400;
        res.set_content("Missing X-Filename header", "text/plain");
        return;
    }

    std::ofstream outFile("../../uploads/" + filename, std::ios::binary);
    if (outFile)
    {
        outFile << req.body;
        res.set_content("File received successfully: " + filename, "text/plain");
    }
    else
    {
        res.status = 500;
        res.set_content("Error saving file", "text/plain");
    }
}
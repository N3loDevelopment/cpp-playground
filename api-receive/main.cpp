#include "receiver.cpp"

int main()
{
    Server server;

    std::cout << "server is starting..." << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "Press Strg+C to close the program." << std::endl;

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// netsh advfirewall firewall add rule name="API Server" dir=in action=allow protocol=TCP localport=8080

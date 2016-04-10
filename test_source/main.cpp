#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "scenes.h"
#include "render_window.h"
#include "gui.h"
#include <iostream>
#include <memory>
#include <string>
#include <chrono>
#include <sstream>
#include <network.h>
using namespace std;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define CONSOLE_WIDTH 400
#define CONSOLE_HEIGHT 100



int main()
{
	
	UdpSocket::initializeSockets();

	UdpSocket socket;
	IpAddress address("localhost", 13337);
	Packet packet;
	packet << 1.0f << 2.0f << 3.0f;
	socket.send(address, packet);

	UdpSocket::shutdownSockets();

	return 0;
}
#ifndef NETWORK_LOGIC_H
#define NETWORK_LOGIC_H

#include <actor_update.h>
//#include <SFML/Network.hpp>
#include<network.h>
#include <string>
#include <render_system.h>
#include "controller.h"

#define CONTROLLER_SYSTEM_ID 0

struct NetworkLogic
{
	NetworkLogic(IpAddress address, std::string actorType, Controller& controller, RenderSystem& renderSystem);
	void sendEvents();
	std::vector<std::shared_ptr<ActorUpdate> > receiveUpdates();
	int getActorID();
private:
	void refreshTimeout();
	Controller& controller;
	RenderSystem& renderSystem;
	IpAddress address;
	UdpSocket socket;
	unsigned short localPort;
	int uniqueID;
	int actorID;
	bool scenePushed;
	std::string actorType;
	Packet packet;
	std::map<std::string, File> downloadingFiles;
	std::map<std::string, int> updateNumbers;
	enum class State
	{
		GETTING_UNIQUE_ID,
		CREATING_ACTOR,
		RECEIVING_UPDATES
	};
	State state;
};

#endif
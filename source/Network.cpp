///                                                                           
/// Langulus::Module::Network                                                 
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include "Network.hpp"

LANGULUS_DEFINE_MODULE(
   Network, 0, "Network",
   "Network module, able to connect to, or host sessions", "",
   Network, Client, Server, Shared
)


/// Module construction                                                       
///   @param runtime - the runtime that owns the module                       
///   @param descriptor - instructions for configuring the module             
Network::Network(Runtime* runtime, const Neat&)
   : Resolvable{this}
   , A::Module {runtime}
   , mClients {this}
   , mServers {this} {
   VERBOSE_NETWORK("Initializing...");
   VERBOSE_NETWORK("Initialized");
}

///                                                                           
Network::~Network() {

}

/// Module update routine                                                     
///   @param deltaTime - time between updates                                 
///   @return false if the UI requested exit                                  
bool Network::Update(Time deltaTime) {
   return true;
}

/// Create/Destroy clients/servers                                            
///   @param verb - the creation/destruction verb                             
void Network::Create(Verb& verb) {
   mClients.Create(verb);
   mServers.Create(verb);
}
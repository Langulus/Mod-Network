///                                                                           
/// Langulus::Module::Network                                                 
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Shared.hpp"
#include "Client.hpp"
#include <Flow/Verbs/Create.hpp>


///                                                                           
///   Server                                                                  
///                                                                           
/// Produces shared objects and syncronizes them with all connected clients.  
///                                                                           
struct Server final : A::Unit, ProducedFrom<Network> {
   LANGULUS(ABSTRACT) false;
   LANGULUS(PRODUCER) Network;
   LANGULUS_BASES(A::Unit);
   LANGULUS_VERBS(Verbs::Create);

private:
   // List of synchronized objects                                      
   TFactory<Shared> mShared;
   // List of connected clients                                         
   TFactory<Client> mClients;

public:
    Server(Network*, const Neat&);
   ~Server();

   void Create(Verb&);
   void Refresh();
};
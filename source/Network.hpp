///                                                                           
/// Langulus::Module::Network                                                 
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Client.hpp"
#include "Server.hpp"
#include <Flow/Verbs/Create.hpp>


///                                                                           
///   Network module                                                          
///                                                                           
/// Manages and produces clients/servers                                      
///                                                                           
struct Network final : A::Module {
   LANGULUS(ABSTRACT) false;
   LANGULUS_BASES(A::Module);
   LANGULUS_VERBS(Verbs::Create);

private:
   // List of created clients                                           
   TFactory<Client> mClients;
   // List of created servers                                           
   TFactory<Server> mServers;

public:
    Network(Runtime*, const Neat&);
   ~Network();

   bool Update(Time);
   void Create(Verb&);
};
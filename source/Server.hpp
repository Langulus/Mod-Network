///                                                                           
/// Langulus::Module::Network                                                 
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Shared.hpp"
#include <Flow/Verbs/Create.hpp>


///                                                                           
///   Network server                                                          
///                                                                           
/// Produces shared objects and syncronizes them with all connected clients   
///                                                                           
struct Server final : A::Server, ProducedFrom<Network> {
   LANGULUS(ABSTRACT) false;
   LANGULUS(PRODUCER) Network;
   LANGULUS_BASES(A::Server);
   LANGULUS_VERBS(Verbs::Create);

private:
   // List of synchronized objects                                      
   TFactory<Shared> mShared;

public:
    Server(Network*, Describe);
   ~Server();

   void Create(Verb&);
   void Refresh();
};
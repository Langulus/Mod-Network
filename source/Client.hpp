///                                                                           
/// Langulus::Module::Network                                                 
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Shared.hpp"
#include <Langulus/Flow/Factory.hpp>
#include <Langulus/Verbs/Create.hpp>


///                                                                           
///   Network client                                                          
///                                                                           
/// Produces shared objects and syncronizes them with a connected server.     
///                                                                           
struct Client final : A::Client, ProducedFrom<Network> {
   using CTTI_Abstract = No;
   using CTTI_Producer = Network;
   LANGULUS_BASES(A::Client);
   LANGULUS_VERBS(Verbs::Create);

private:
   // List of synchronized objects                                      
   TFactory<Shared> mShared;

public:
   Client(Network*, Many const&);

   void Create(Verb&);
   void Refresh();
   void Teardown();
};
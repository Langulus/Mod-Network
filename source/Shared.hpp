///                                                                           
/// Langulus::Module::Network                                                 
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Common.hpp"


///                                                                           
///   Shared object                                                           
///                                                                           
/// Dispatches any events on the network.                                     
///                                                                           
struct Shared final : A::Unit, ProducedFrom<Server> {
   LANGULUS(ABSTRACT) false;
   LANGULUS(PRODUCER) Server;
   LANGULUS_BASES(A::Unit);

public:
   Shared(Server*, const Neat&);
   
   void Refresh();
};
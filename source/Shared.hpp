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
struct Shared final : A::NetworkUnit, ProducedFrom<A::NetworkUnit> {
   LANGULUS(ABSTRACT) false;
   LANGULUS(PRODUCER) A::NetworkUnit;
   LANGULUS_BASES(A::NetworkUnit);

public:
   Shared(Server*, const Neat&);
   Shared(Client*, const Neat&);
   
   void Refresh();
};
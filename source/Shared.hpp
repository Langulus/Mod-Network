///                                                                           
/// Langulus::Module::Network                                                 
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Common.hpp"
#include <Langulus/Flow/Producible.hpp>


///                                                                           
///   Shared object                                                           
///                                                                           
/// Dispatches any events on the network.                                     
///                                                                           
struct Shared final : A::Shared, ProducedFrom<A::NetworkUnit> {
   using CTTI_Abstract = No;
   using CTTI_Producer = A::NetworkUnit;
   LANGULUS_BASES(A::Shared);

public:
   Shared(A::NetworkUnit*, Many const&);
   
   void Refresh();
};
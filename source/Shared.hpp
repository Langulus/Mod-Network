///                                                                           
/// Langulus::Module::Network                                                 
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Export.hpp"
#include <Langulus/Producible.hpp>


///                                                                           
///   Shared object                                                           
///                                                                           
/// Dispatches any events on the network.                                     
///                                                                           
struct Shared final : Things::Shared, ProducedFrom<Things::NetworkPart> {
   using CTTI_Abstract  = No;
   using CTTI_Producer  = Things::NetworkPart;
   using CTTI_Bases     = Things::Shared;

public:
   Shared(Things::NetworkPart*, Many const&);
   
   void Refresh();
};
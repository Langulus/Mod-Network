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
///   Network client                                                          
///                                                                           
struct Client final : A::Unit, ProducedFrom<Network> {
   LANGULUS(ABSTRACT) false;
   LANGULUS(PRODUCER) Network;
   LANGULUS_BASES(A::Unit);

public:
   Client(Network*, const Neat&);
   ~Client();

   void Refresh();
};
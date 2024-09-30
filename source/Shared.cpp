///                                                                           
/// Langulus::Module::Network                                                 
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include "Shared.hpp"
#include "Server.hpp"
#include "Client.hpp"


/// Shared object construction                                                
///   @param producer - the producer                                          
///   @param descriptor - instructions for configuring the shared object      
Shared::Shared(A::NetworkUnit* producer, const Many& descriptor)
   : Resolvable   {this}
   , ProducedFrom {producer, descriptor} {
   VERBOSE_NETWORK("Initializing...");
   Couple(descriptor);
   VERBOSE_NETWORK("Initialized");
}

/// React on environmental change                                             
void Shared::Refresh() {

}

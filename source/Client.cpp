///                                                                           
/// Langulus::Module::Network                                                 
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include "Client.hpp"
#include "Network.hpp"


/// Gatherer construction                                                     
///   @param producer - the system producer                                   
///   @param descriptor - instructions for configuring the GUI                
Client::Client(Network* producer, const Neat& descriptor)
   : Resolvable   {this}
   , ProducedFrom {producer, descriptor}
   /*, mShared      {this}*/ {
   VERBOSE_NETWORK("Initializing...");
   Couple(descriptor);
   VERBOSE_NETWORK("Initialized");
}

/// Shutdown the client                                                       
Client::~Client() {

}

/// Produce shared objects                                                    
///   @param verb - creation verb to satisfy                                  
void Client::Create(Verb& verb) {
   mShared.Create(this, verb);
}

/// React on environmental change                                             
void Client::Refresh() {

}

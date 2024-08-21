///                                                                           
/// Langulus::Module::Network                                                 
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include "Server.hpp"
#include "Network.hpp"


/// Gatherer construction                                                     
///   @param producer - the system producer                                   
///   @param descriptor - instructions for configuring the server             
Server::Server(Network* producer, const Neat& descriptor)
   : Resolvable   {this}
   , ProducedFrom {producer, descriptor} {
   VERBOSE_NETWORK("Initializing...");
   Couple(descriptor);
   VERBOSE_NETWORK("Initialized");
}

/// Shutdown the module                                                       
Server::~Server() {

}

/// Produce shared objects                                                    
///   @param verb - creation verb to satisfy                                  
void Server::Create(Verb& verb) {
   mShared.Create(this, verb);
}

/// React on environmental change                                             
void Server::Refresh() {

}

///                                                                           
/// Langulus::Module::Network                                                 
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include <Langulus.hpp>

using namespace Langulus;

struct Network;
struct Client;
struct Server;
struct Shared;

#if 1
   #define VERBOSE_NETWORK_ENABLED() 1
   #define VERBOSE_NETWORK(...)      Logger::Network(Self(), __VA_ARGS__)
   #define VERBOSE_NETWORK_TAB(...)  const auto tab = Logger::NetworkTab(Self(), __VA_ARGS__)
#else
   #define VERBOSE_NETWORK_ENABLED() 0
   #define VERBOSE_NETWORK(...)      LANGULUS(NOOP)
   #define VERBOSE_NETWORK_TAB(...)  LANGULUS(NOOP)
#endif
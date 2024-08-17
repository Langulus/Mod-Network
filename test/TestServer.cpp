///                                                                           
/// Langulus::Module::Network                                                 
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include "Main.hpp"
#include <Langulus/Network.hpp>
#include <catch2/catch.hpp>


/// See https://github.com/catchorg/Catch2/blob/devel/docs/tostring.md        
CATCH_TRANSLATE_EXCEPTION(::Langulus::Exception const& ex) {
   const Text serialized {ex};
   return ::std::string {Token {serialized}};
}

SCENARIO("Server creation", "[network]") {
   static Allocator::State memoryState;

   for (int repeat = 0; repeat != 10; ++repeat) {
      GIVEN(std::string("Init and shutdown cycle #") + std::to_string(repeat)) {
         // Create root entity                                          
         auto root = Thing::Root<false>("Network");

         WHEN("The Server and Shared created via abstractions") {
            auto server = root.CreateUnit<A::Server>();
            auto shared = root.CreateUnit<A::Shared>();

            // Update once                                              
            root.Update({});
            root.DumpHierarchy();

            REQUIRE(server.GetCount() == 1);
            REQUIRE(server.CastsTo<A::Server>(1));
            REQUIRE(server.IsSparse());

            REQUIRE(shared.GetCount() == 1);
            REQUIRE(shared.CastsTo<A::Shared>(1));
            REQUIRE(shared.IsSparse());

            REQUIRE(root.GetUnits().GetCount() == 2);
         }

      #if LANGULUS_FEATURE(MANAGED_REFLECTION)
         WHEN("The Server and Shared created via tokens") {
            auto server = root.CreateUnitToken("Server");
            auto shared = root.CreateUnitToken("Shared");

            // Update once                                              
            root.Update({});
            root.DumpHierarchy();

            REQUIRE(server.GetCount() == 1);
            REQUIRE(server.CastsTo<A::Server>(1));
            REQUIRE(server.IsSparse());

            REQUIRE(shared.GetCount() == 1);
            REQUIRE(shared.CastsTo<A::Shared>(1));
            REQUIRE(shared.IsSparse());

            REQUIRE(root.GetUnits().GetCount() == 2);
         }
      #endif

         // Check for memory leaks after each cycle                     
         REQUIRE(memoryState.Assert());
      }
   }
}


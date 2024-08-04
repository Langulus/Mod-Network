cmake_minimum_required(VERSION 3.28)
project(LangulusModNetwork
    VERSION         1.0.0
    DESCRIPTION     "Langulus plug-in module that provides networking client/server capabilities"
    HOMEPAGE_URL    https://langulus.com
)

file(GLOB_RECURSE
    LANGULUS_MOD_NETWORK_SOURCES 
    LIST_DIRECTORIES FALSE CONFIGURE_DEPENDS
    source/*.cpp
)

# Build the module                                                              
add_library(LangulusModNetwork SHARED ${LANGULUS_MOD_NETWORK_SOURCES})

target_link_libraries(LangulusModNetwork
    PRIVATE     Langulus
)

if(LANGULUS_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()
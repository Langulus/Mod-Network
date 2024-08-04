file(GLOB_RECURSE
	LANGULUS_MOD_NETWORK_TEST_SOURCES 
	LIST_DIRECTORIES FALSE CONFIGURE_DEPENDS
	*.cpp
)

add_executable(LangulusModNetworkTest ${LANGULUS_MOD_NETWORK_TEST_SOURCES})

target_link_libraries(LangulusModNetworkTest
	PRIVATE		Langulus
				Catch2
)

add_dependencies(LangulusModNetworkTest
	LangulusModNetwork
)

add_test(
	NAME		LangulusModNetworkTest
	COMMAND		LangulusModNetworkTest
	WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
file(GLOB_RECURSE
	LANGULUS_MOD_NETWORK_TEST_SOURCES 
	LIST_DIRECTORIES FALSE CONFIGURE_DEPENDS
	*.cpp
)

add_langulus_test(LangulusModNetworkTest
	SOURCES			${LANGULUS_MOD_NETWORK_TEST_SOURCES}
	LIBRARIES		Langulus
	DEPENDENCIES    LangulusModNetwork
)
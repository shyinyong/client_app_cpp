cmake_minimum_required(VERSION 3.22)
project(client)

link_libraries(ws2_32)

set(CMAKE_CXX_STANDARD 11)

include_directories(misc)
include_directories(pugixml)

add_executable(client
        pugixml/pugiconfig.hpp
        pugixml/pugixml.cpp
        pugixml/pugixml.hpp
        xml_utils.cpp
        xml_utils.h
        client_app.cpp
        client_app.h
        block_buffer.hpp
        main.cpp
        )

FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

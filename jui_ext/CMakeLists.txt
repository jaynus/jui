cmake_minimum_required (VERSION 2.6)
project (jui)

if (NOT CMAKE_BUILD_TYPE AND CMAKE_COMPILER_IS_GNUCXX)
	message(STATUS "No build type selected, default to Debug")
	set(CMAKE_BUILD_TYPE "Debug")
endif()

set(JNET_SOURCES CallExt_DllMain.cpp hooker.hpp hooker.cpp logging.hpp 
				 ini.h ini.cpp text_message.hpp text_message.cpp ini_reader.hpp ini_reader.cpp 
				 easyloggingc++.hpp)
				 
if(CMAKE_COMPILER_IS_GNUCXX)
	SET(CMAKE_CXX_FLAGS "-std=c++11 -march=i686 -m32 -O2 -s -fPIC -fpermissive")
	set(LINUX_SOURCES ../plthook/plthook_elf.cpp  ../plthook/plthook.h)
	include_directories(../)
	set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
	set(CMAKE_SHARED_LINKER_FLAGS "-static-libgcc -static-libstdc++")
else()

	set(CMAKE_CXX_FLAGS_DEBUG "/D _DEBUG /MTd /Zi /Ob0 /Od /RTC1")
	set(CMAKE_CXX_FLAGS_MINSIZEREL     "/MT /O1 /Ob1 /D NDEBUG")
	set(CMAKE_CXX_FLAGS_RELEASE       "/MT /O2 /Ob2 /D NDEBUG")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MT /Zi /O2 /Ob1 /D NDEBUG")
	
	include_directories ("E:/dev/Detours3.0/src")
	link_directories("E:/dev/Detours3.0/lib.X86")

#	include_directories ("E:/dev/DirectX_June2010/include")
#	link_directories("E:/dev/DirectX_June2010/lib/x86")
	set(LINUX_SOURCES )
endif()

add_library( jui SHARED ${LINUX_SOURCES} ${JNET_SOURCES})
SET_TARGET_PROPERTIES(jui PROPERTIES PREFIX "")

				 
if(CMAKE_COMPILER_IS_GNUCXX)
	set_target_properties(jui PROPERTIES LINK_SEARCH_START_STATIC 1)
	set_target_properties(jui PROPERTIES LINK_SEARCH_END_STATIC 1)
endif()

message("Build Type: ${CMAKE_BUILD_TYPE}")

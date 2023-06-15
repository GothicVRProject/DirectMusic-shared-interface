cmake_minimum_required(VERSION 3.5)

project(dmusic-shared-library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_SHARED_LIBRARY_PREFIX "lib")

if (NOT MSVC)
    # Make sure everything is relocatable.
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif ()

add_subdirectory(vendor/dmusic)

# Find all source files in the source directory

set(DMSC_SOURCES
src/directmusic.cc
src/music.cc
src/mixer.cc)

add_library(dmusic-shared SHARED)
set_target_properties(dmusic-shared PROPERTIES CXX_VISIBILITY_PRESET hidden VISIBILITY_INLINES_HIDDEN 1)
target_compile_definitions(dmusic-shared PRIVATE DMSC_EXPORTS=1)
target_sources(dmusic-shared PRIVATE ${DMSC_SOURCES})
target_include_directories(dmusic-shared PUBLIC include)
target_link_libraries(dmusic-shared dmusic)

if (MINGW)
    # We need to "bake" standard C/C++ libraries and windows pthread into DLL
    # Otherwise we need to distribute up to 3 dlls within the same folder.
    # If we don't do any of this, we'll get the following error (or a similar one):
    # -> The procedure entry point _ZNKSt7codecvtlwc9_MbstatetE10do_unshiftERS0_PcS3_RS3_ could not be located in the dynamic link library [...]\build\test_lib.exe
    # -> Dll couldn't be loaded as dependencies are missing.
    target_link_options(dmusic-shared PUBLIC "-static")
endif()

install(TARGETS dmusic-shared ARCHIVE LIBRARY RUNTIME)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/dmusic" TYPE INCLUDE)



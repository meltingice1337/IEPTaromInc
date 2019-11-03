project(avion_lib)

add_library(avion_lib src/aripi.cc src/motoare.cc src/corp.cc src/avion.cc src/avion_marfa.cc src/avion_pasageri.cc)

target_include_directories(avion_lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    PRIVATE src)

export(TARGETS avion_lib FILE AvionLibConfig.cmake)

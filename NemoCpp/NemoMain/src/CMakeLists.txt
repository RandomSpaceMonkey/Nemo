include_directories(${NemoCPP_SOURCE_DIR}/NemoLib/include)
link_directories(${NemoCPP_SOURCE_DIR}/NemoLib/src)
add_executable(NemoMain main.cc)
target_link_libraries(NemoMain NemoLib)

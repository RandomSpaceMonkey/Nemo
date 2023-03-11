include_directories(${NemoCPP_SOURCE_DIR}/NemoLib/include)
add_library(NemoLib action.cc args.cc encoder.cc filetype.cc pngencoder.cc utils.cc pngchunk.cc)
aux_source_directory(. DIR_SRC)

add_library(complib STATIC ${DIR_SRC})

target_include_directories(complib PUBLIC .)
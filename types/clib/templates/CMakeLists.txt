set(LIB_NAME TMPL_CLIB_NAME)
add_library(${LIB_NAME} OBJECT ${LIB_NAME}.c)
# add_library(${LIB_NAME} ALIAS ${LIB_NAME}.c)
# add_library(${LIB_NAME} IMPORTED ${LIB_NAME}.c)
# add_library(${LIB_NAME} INTERFACE ${LIB_NAME}.c)
# add_library(${LIB_NAME} MODULE ${LIB_NAME}.c)
# add_library(${LIB_NAME} SHARED ${LIB_NAME}.c)
# add_library(${LIB_NAME} STATIC ${LIB_NAME}.c)
# add_library(${LIB_NAME} UNKNOWN ${LIB_NAME}.c)

# Require anyone linking to this library to include the current source
# directory.
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


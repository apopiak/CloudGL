
# 
# External dependencies
# 

# find_package(THIRDPARTY REQUIRED)


# 
# Executable name and options
# 

# Target name
set(target CloudGLClient)

# Exit here if required dependencies are not met
message(STATUS "Application ${target}")


# 
# Sources
# 

set(sources
    main.cpp
    CloudGLClient.cpp
    CloudGLClient.h
    CreateSessionDialog.cpp
    CreateSessionDialog.h
)


#
# Qt5 UI
#

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(uis
        CloudGLClient.ui
        CreateSessionDialog.ui
        )

QT5_WRAP_UI(ui_headers ${uis})

message("UI Headerss: ${ui_headers}")

# 
# Create executable
# 

# Build executable
add_executable(${target}
    MACOSX_BUNDLE
    ${sources}
    ${ui_headers}
)

# Create namespaced alias
add_executable(${META_PROJECT_NAME}::${target} ALIAS ${target})


# 
# Project options
# 

set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
    FOLDER "${IDE_FOLDER}"
)


# 
# Include directories
# 

target_include_directories(${target}
    PRIVATE
    ${DEFAULT_INCLUDE_DIRECTORIES}
    ${PROJECT_BINARY_DIR}/source/include
)


# 
# Libraries
# 

target_link_libraries(${target}
    PRIVATE
    ${DEFAULT_LIBRARIES}
    ${META_PROJECT_NAME}::CloudGLCommon
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)


# 
# Compile definitions
# 

target_compile_definitions(${target}
    PRIVATE
    ${DEFAULT_COMPILE_DEFINITIONS}
)


# 
# Compile options
# 

target_compile_options(${target}
    PRIVATE
    ${DEFAULT_COMPILE_OPTIONS}
)


# 
# Linker options
# 

target_link_libraries(${target}
    PRIVATE
    ${DEFAULT_LINKER_OPTIONS}
)


# 
# Deployment
# 

# Executable
install(TARGETS ${target}
    RUNTIME DESTINATION ${INSTALL_BIN} COMPONENT examples
    BUNDLE  DESTINATION ${INSTALL_BIN} COMPONENT examples
)

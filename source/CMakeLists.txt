
# 
# Configuration for all sub-projects
# 

# Generate version-header
string(TOUPPER ${META_PROJECT_NAME} META_PROJECT_NAME_UPPER)
configure_file(version.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/${META_PROJECT_NAME}/${META_PROJECT_NAME}-version.h)

#
# Global Include Directories
#

include_directories(
    common/
)

# 
# Sub-projects
# 

# Libraries
set(IDE_FOLDER "")
add_subdirectory(common)

# Applications
set(IDE_FOLDER "Applications")
add_subdirectory(broker)
add_subdirectory(client)
add_subdirectory(server)

# Wrapper
set(IDE_FOLDER "Wrappers")
add_subdirectory(wrapper)

# Tests
set(IDE_FOLDER "Tests")
add_subdirectory(tests)


# 
# Deployment
# 

# Deploy generated headers
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/${META_PROJECT_NAME} DESTINATION include COMPONENT dev)

cmake_minimum_required (VERSION 3.22)

#---- Project Configuration
set(MAJOR 0)
set(MINOR 1)
set(PATCH 0)

project(
	wxWidgetsTemplate
	LANGUAGES CXX
	VERSION ${MAJOR}.${MINOR}.${PATCH}
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(OUTPUT_HEADERS ${CMAKE_CURRENT_BINARY_DIR}/include)


#---- Generate Headers
file(GLOB_RECURSE TEMPLATE_HEADERS ./resources/headers/*.h.in)
foreach(OLDFILE ${TEMPLATE_HEADERS})
	get_filename_component(NEWFILE ${OLDFILE} NAME_WLE)
	configure_file(${OLDFILE} ${OUTPUT_HEADERS}/${NEWFILE})
endforeach()
include_directories(${OUTPUT_HEADERS})

#---- wxWidgets
set(wxBUILD_SHARED OFF)
add_subdirectory(./dependencies/wxWidgets)

#---- Compilation
file(GLOB_RECURSE PROJECT_SOURCE ./src/*.cpp ./src/*.h)
add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SOURCE})

#---- Linking
target_link_libraries(
	${PROJECT_NAME}
	wx::net wx::core wx::base
)

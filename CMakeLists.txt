# CMakeList.txt : CMake project for Raycaster_Test_5.31.2025, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(RAYLIB_VERSION 5.5)

find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED

if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
  endif()
endif()

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Raycaster_Test_5.31.2025")

# Add source to this project's executable.
add_executable (Raycaster_Test_5.31.2025 "src/main.cpp"  "src/RenderThreeD.h" "src/RenderTwoD.h" "src/RenderTwoD.cpp" "src/RenderThreeD.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Raycaster_Test_5.31.2025 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
# Link raylib
target_link_libraries(${PROJECT_NAME} raylib)
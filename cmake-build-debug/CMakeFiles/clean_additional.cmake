# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/database_project_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/database_project_autogen.dir/ParseCache.txt"
  "database_project_autogen"
  )
endif()

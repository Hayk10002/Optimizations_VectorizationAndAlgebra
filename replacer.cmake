# Usage:
# cmake -DINPUT=path/to/input.hpp -DOUTPUT=path/to/output.hpp -DTARGET_NAME=your_target -DTARGET_PATH=/actual/path -P replace_target_dir.cmake

if(NOT INPUT OR NOT OUTPUT OR NOT TARGET_NAME OR NOT TARGET_PATH)
  message(FATAL_ERROR "❌ Missing required variables: INPUT, OUTPUT, TARGET_NAME, or TARGET_PATH")
endif()

# Read the original file content
file(READ "${INPUT}" _content)

# Replace the literal generator expression with the actual target path
set(_pattern "$<TARGET_FILE_DIR:${TARGET_NAME}>")
string(REPLACE "${_pattern}" "${TARGET_PATH}" _content "${_content}")

# Write the updated content to OUTPUT file
file(WRITE "${OUTPUT}" "${_content}")

message(STATUS "✅ Replaced '${_pattern}' with '${TARGET_PATH}' in '${OUTPUT}'")

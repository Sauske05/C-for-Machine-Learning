# Define the executable
add_executable(TestTorch "TestTorch.cpp")  # Adjust to your actual source file name

# Link against Torch libraries
target_link_libraries(TestTorch PRIVATE ${TORCH_LIBRARIES})

# Copy DLLs for Windows
if(MSVC)
    foreach(lib ${TORCH_LIBRARIES})
        add_custom_command(TARGET TestTorch
                           POST_BUILD
                           COMMAND ${CMAKE_COMMAND} -E copy_if_different
                           "${lib}"
                           $<TARGET_FILE_DIR:TestTorch>)
    endforeach()
endif()
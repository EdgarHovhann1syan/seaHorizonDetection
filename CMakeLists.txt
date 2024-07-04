cmake_minimum_required(VERSION 3.10)
project(SeaImageProcessing)

set(CMAKE_CXX_STANDARD 14)

# Найти пакет OpenCV
find_package(OpenCV REQUIRED)

# Включить директории с заголовочными файлами
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(
  include
)
# Добавить исполняемый файл
add_executable(SeaImageProcessing 
    ${PROJECT_SOURCE_DIR}/src/main.cpp 
    ${PROJECT_SOURCE_DIR}/src/image_processing.cpp
)

# Подключить библиотеки OpenCV
target_link_libraries(SeaImageProcessing ${OpenCV_LIBS})




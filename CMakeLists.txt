cmake_minimum_required(VERSION 3.5.0)
project(Space-battle VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Добавляем библиотеку CTest
#find_package(CTest REQUIRED)
# Создаем директории для исходного кода и тестов
set(SOURCE_FILES main.cpp Movable.cpp)

# Указываем, что мы хотим скомпилировать тесты
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
add_executable(test1 Test1.cpp)
#add_executable(test2 Test2.cpp)
#add_executable(test3 Test3.cpp)
#add_executable(test4 Test4.cpp)
#add_executable(test5 Test5.cpp)

# Указываем, что мы хотим запустить тесты

enable_testing()
add_test(NAME test1 COMMAND test1)
#add_test(NAME test2 COMMAND test2)
#add_test(NAME test3 COMMAND test3)
#add_test(NAME test4 COMMAND test4)
#add_test(NAME test5 COMMAND test5)

# Устанавливаем переменную CTEST_OUTPUT_ON_FAILURE, чтобы увидеть вывод тестов при неудачном завершении
set(CTEST_OUTPUT_ON_FAILURE ON)


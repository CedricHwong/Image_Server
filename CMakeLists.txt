cmake_minimum_required(VERSION 3.15)
project(Image_Service)

set(CMAKE_CXX_STANDARD 20)

link_directories("./openssl_lib/")
link_libraries(libcrypto.a)

link_directories(/usr/local/mysql/lib)
link_libraries(libmysqlclient.a)

###########################################################################################

#add_executable(Image_Service SourceCpp/main.cpp  SourceCpp/)
add_executable(Image_Service SourceCpp/main.cpp SourceCpp/jsoncpp.cpp)
add_executable(mysql_insert SourceCpp/mysql_insert.cpp)
add_executable(mysql_select SourceCpp/mysql_select.cpp)
add_executable(mysql_test SourceCpp/db_test.cpp SourceCpp/jsoncpp.cpp)
include_directories(/usr/local/mysql/include)
#include_directories(/usr/local/Cellar/jsoncpp/1.9.1/include/json)
include_directories(./SourceHpp)
include_directories(./wwwroot)
#include_directories(./openssl)


###########################################################################################
target_link_libraries(Image_Service -lcrypto)
target_link_libraries(mysql_insert -lmysqlclient)
target_link_libraries(mysql_select -lmysqlclient)
target_link_libraries(mysql_test -lmysqlclient)

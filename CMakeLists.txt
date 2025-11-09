cmake_minimum_required(VERSION 3.16)
project(MeuProjetoQt)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "C:/Qt/6.9.3/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(SOURCES
    main.cpp
    MainWindow.cpp
    Cliente.cpp
    Pedido.cpp
    Barzinho.cpp
    sqlite3.c
)

set(HEADERS
    MainWindow.h
    Cliente.h
    Pedido.h
    Bebidas.h
    Aperitivo.h
    Barzinho.h
    Produto.h
    sqlite3.h
)

add_executable(Barzinho ${SOURCES} ${HEADERS} mainwindow.ui
    telacardapio.ui
    telacardapio.ui
    telacardapio.h telacardapio.cpp telacardapio.ui
    telafinal.h telafinal.cpp telafinal.ui
)

target_link_libraries(Barzinho Qt6::Widgets)

# Se usar arquivos .ui, o CMake já processa via AUTOMOC
set_target_properties(Barzinho PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)

cmake_minimum_required(VERSION 3.17)
project(qt6-semi-transparency-example)

find_package(Qt6 COMPONENTS Core Quick QuickControls2 Widgets)
find_program(WINDEPLOYQT windeployqt)

set(PROJECT_SOURCES
    app/main.cpp
    resources/qml.qrc
)
set (QML_SOURCES    
    resources/qml/main.qml
)
set(QML_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources/qml)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${QML_SOURCES})
source_group("qml" FILES ${QML_SOURCES})
target_compile_definitions(${PROJECT_NAME}
    PRIVATE $<IF:$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>,QT_QML_DEBUG,QT_NO_DEBUG_OUTPUT>)
target_link_libraries(
    ${PROJECT_NAME} 
    PUBLIC Qt${QT_VERSION_MAJOR}::Core 
            Qt${QT_VERSION_MAJOR}::Quick 
            Qt${QT_VERSION_MAJOR}::QuickControls2
            Qt${QT_VERSION_MAJOR}::Widgets
)
set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC TRUE)
set_target_properties(${PROJECT_NAME} PROPERTIES AUTORCC TRUE)
if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
        COMMAND ${WINDEPLOYQT} --qmldir ${QML_SOURCES_DIR} $<TARGET_FILE:${PROJECT_NAME}>
    )
endif()
cmake_minimum_required(VERSION 3.17)
project(qt6-semi-transparency-example)

find_package(Qt6 COMPONENTS Core Quick QuickControls2 Widgets)
find_program(WINDEPLOYQT windeployqt)

set(PROJECT_SOURCES
    app/main.cpp
)
set (QML_RESOURCES    
    resources/qml/main.qml
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${QML_RESOURCES})
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
if(WIN32)
    set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DPI_AWARE "ON")
    add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD 
        COMMAND ${CMAKE_COMMAND} -E remove_directory \"$<TARGET_FILE_DIR:${PROJECT_NAME}>/qml\"
        COMMAND mklink /J \"$<TARGET_FILE_DIR:${PROJECT_NAME}>/qml\" \"${CMAKE_CURRENT_SOURCE_DIR}/resources/qml\")
endif()

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
    COMMAND ${WINDEPLOYQT} --qmldir $<TARGET_FILE_DIR:${PROJECT_NAME}>/qml $<TARGET_FILE:${PROJECT_NAME}>
)
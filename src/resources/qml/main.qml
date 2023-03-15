import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Controls.Material

ApplicationWindow {
    color: "transparent"
    Material.theme: Material.Dark
    width: 300
    height: 300
    visible: true

    Rectangle { 
        anchors.fill: parent
        radius: 10
        color: Material.background
    }
}
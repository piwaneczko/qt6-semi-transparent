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

    
    Component.onCompleted: {
        textBox.text = "Hello world"
    }
    

    Rectangle { 
        anchors.fill: parent
        radius: 10
        color: Material.background

        Text { 
            id: textBox   
            color: Material.foreground
            anchors.centerIn: parent
        }
    }
}
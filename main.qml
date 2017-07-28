import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Window 2.2
import QtQuick.Controls.Material 2.1

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    x: Screen.width / 2 - width / 2
    y: Screen.height / 2 - height / 2
    title: qsTr("Cute CPUInfo")

    header: ToolBar {
        id: toolbarHeader
        Material.foreground: "white"

        RowLayout {
            anchors.fill: parent

            Label {
                id: titleLabel
                text: "CPU Info"
                font.pixelSize: 20
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }

            ToolButton {
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "images/menu.png"
                }
                onClicked: optionsMenu.open()

                Menu {
                    id: optionsMenu
                    x: parent.width - width
                    transformOrigin: Menu.TopRight

                    MenuItem {
                        text: "About"
                        onTriggered: aboutDialog.open()
                    }
                }
            }
        }
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: indicator.currentIndex

        Repeater {
            model: cpuCount
            delegate: Pane {
                property int pageIndex: index
                Material.background: "skyblue"

                ListView {
                    id: cpuInfoListView
                    model: eval("cpuInfoModel"+pageIndex)
                    anchors.fill: parent

                    delegate: ItemDelegate {
                        width: parent.width
                        height: 50
                        ColumnLayout {
                            Rectangle {
                                 id: rectName
                                 anchors.top: parent.top
                                 Layout.fillWidth: true
                                 height: 20
                                 Text {
                                     anchors.fill: parent
                                     text: name
                                     font.bold: true
                                 }
                             }
                             Rectangle {
                                 id: rectVal
                                 anchors.top: rectName.bottom
                                 Layout.fillWidth: true
                                 height: 20
                                 Text {
                                     anchors.fill: parent
                                     text: value
                                 }
                             }
                        }
                    }

                    ScrollIndicator.vertical: ScrollIndicator { }
                }
            }
        }
    }

    footer: ToolBar {
        id: toolbarFooter
        Material.foreground: "black"

        RowLayout {
            anchors.fill: parent

            PageIndicator {
                id: indicator
                count: swipeView.count
                currentIndex: swipeView.currentIndex
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    Dialog {
        id: aboutDialog
        modal: true
        title: "About CPU Info"
        x: mainWindow.width / 2 - width / 2

        contentItem: Rectangle {
            Text {
                text: "Cute CPUInfo 1.0, Copyright 2017-2018, Mohamed Mostafa"
                color: "navy"
            }
        }

    }
}

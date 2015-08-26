import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import PdfTools 1.0

Item {

    width: 200
    height: 200

    Poppler {
        anchors.fill: parent
        anchors.bottom: transport.top
        id: doc
        pagenumber: 1
        filename: "/Users/james/data/pdf/scan1.pdf"
    }


    Row {
        anchors.fill: parent
        id: transport

        Button {
            id: pagePrevious
            anchors.left: transport.left
            text: "<"
        }
        Label {
            anchors.top: transport.top
            anchors.left: pagePrevious.right
            anchors.right: pageNext.left
            text: "page " + doc.pagenumber + " of "  + doc.pageCount
            horizontalAlignment: "AlignHCenter"
        }
        Button {
            id: pageNext
            anchors.right: transport.right
            text: ">"
        }
    }



}

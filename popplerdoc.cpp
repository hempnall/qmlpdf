#include "popplerdoc.h"
#include <QImage>
#include <QDebug>
#include <QPainter>

PopplerDoc::PopplerDoc(QQuickPaintedItem* parent)
    : QQuickPaintedItem(parent),pageCount_(0),document_(0),pdfPage_(0)
{

}

PopplerDoc::~PopplerDoc()
{

}

int PopplerDoc::pageCount() const   {
    return pageCount_;
}

QString PopplerDoc::filename() const    {
    return filename_;
}

void PopplerDoc::setPageCount(int pageCount) {
    if (pageCount != pageCount_) {
        pageCount_ = pageCount;
        qDebug() << "pagecount = " << pageCount;
        emit pageCountChanged();
    }
}

void PopplerDoc::setFilename(const QString& filename)   {

    if (filename != filename_) {
        filename_ = filename;
        if (document_) {
            delete document_;
        }
        document_ = Poppler::Document::load(filename);
        document_->setRenderBackend(Poppler::Document::ArthurBackend);
        setPageCount(  document_->numPages() );
        emit filenameChanged();
    }


}

int PopplerDoc::pageNumber() const  {
    return pageNumber_;
}

void PopplerDoc::setPageNumber(int pageNumber)  {
    pageNumber_ = pageNumber;
    if (pdfPage_ ) {
        delete pdfPage_;
    }
    pdfPage_ = document_->page(pageNumber);
    qDebug( ) << "pagenumber=" << pageNumber;
    update();
}

void PopplerDoc::paint(QPainter *painter) {
    if (pdfPage_) {
        pdfPage_->renderToPainter(painter);
//        QImage image = pdfPage_->renderToImage();
//        painter->drawImage(0,0,image);
    } else {

    }
}

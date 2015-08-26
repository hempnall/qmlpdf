#ifndef POPPLER_H
#define POPPLER_H

#include <QQuickPaintedItem>
#include <poppler-qt5.h>


class PopplerDoc : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(int pageCount READ pageCount NOTIFY pageCountChanged)
    Q_PROPERTY(QString filename READ filename WRITE setFilename NOTIFY filenameChanged)
    Q_PROPERTY(int pagenumber READ pageNumber WRITE setPageNumber)

public:
    PopplerDoc(QQuickPaintedItem* parent = 0 );
    ~PopplerDoc();


    int pageCount() const;
    QString filename() const;
    int pageNumber() const;

    void setPageNumber(int pageNumber);

    void setFilename(const QString& filename);

    void paint(QPainter *painter);

signals:
    void pageCountChanged();
    void filenameChanged();

public slots:


private:
    int pageCount_;
    int pageNumber_;
    QString filename_;
    void setPageCount(int pageCount);
    Poppler::Document* document_;
    Poppler::Page* pdfPage_;



};

#endif // POPPLER_H

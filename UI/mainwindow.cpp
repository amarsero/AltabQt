#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>
#include <QLineEdit>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QKeyEvent>

mainwindow::mainwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainwindow)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_QuitOnClose, true);

    lineEdit = this->children()[0]->findChild<QLineEdit*>();
    listView = this->children()[0]->findChild<QListView*>();

    lineEdit->installEventFilter(this);

    itemModel = new QStandardItemModel(0,0,listView);

    listView->setModel(itemModel);

    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close()));
}

mainwindow::~mainwindow()
{
    delete ui;
}


bool mainwindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        return keyEventFilter(keyEvent);
        return true;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}

bool mainwindow::keyEventFilter(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key::Key_Up:
        {
            GoToAdjecentItem(-1);
            return true;
        }
        case Qt::Key::Key_Down:
        {
            GoToAdjecentItem(1);
            return true;
        }
    }
    return false;
}


void mainwindow::GoToAdjecentItem(int offset)
{
    QModelIndex current = listView->currentIndex();
    if (!current.isValid()) {
        current = listView->indexAt(QPoint(1,0));
        if (current.isValid())
        {
            listView->setCurrentIndex(current);
        }
        return;
    }

    QModelIndex item = current.siblingAtRow(current.row()+offset);
    if (item.isValid())
    {
        listView->setCurrentIndex(item);
    }
}


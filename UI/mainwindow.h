#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QListView>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::mainwindow *ui;
    QLineEdit* lineEdit;
    QListView* listView;
    QStandardItemModel* itemModel;

    bool keyEventFilter(QKeyEvent* keyEvent);

    void GoToAdjecentItem(int offset);
};
#endif // MAINWINDOW_H

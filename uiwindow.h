#ifndef UIWINDOW_H
#define UIWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class UiWindow; }
QT_END_NAMESPACE

class UiWindow : public QWidget
{
    Q_OBJECT

public:
    UiWindow(QWidget *parent = nullptr);
    ~UiWindow();

private:
    Ui::UiWindow *ui;
};
#endif // UIWINDOW_H

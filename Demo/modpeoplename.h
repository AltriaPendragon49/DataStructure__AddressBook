#ifndef MODPEOPLENAME_H
#define MODPEOPLENAME_H

#include <QWidget>

namespace Ui {
class ModPeopleName;
}

class ModPeopleName : public QWidget
{
    Q_OBJECT

public:
    explicit ModPeopleName(QWidget *parent = nullptr);
    ~ModPeopleName();

private slots:
    void on_ok_clicked();
    void on_quit_clicked();
    QString gettextBefore();
    QString gettextAfter();

private:
    Ui::ModPeopleName *ui;
};

#endif // MODPEOPLENAME_H

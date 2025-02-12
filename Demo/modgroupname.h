#ifndef MODGROUPNAME_H
#define MODGROUPNAME_H

#include <QWidget>

namespace Ui {
class modgroupname;
}

class modgroupname : public QWidget
{
    Q_OBJECT

public:
    explicit modgroupname(QWidget *parent = nullptr);
    ~modgroupname();

private slots:
    void on_ok_clicked();
    void on_quit_clicked();
    QString gettextBefore();
    QString gettextAfter();

private:
    Ui::modgroupname *ui;
};

#endif // MODGROUPNAME_H

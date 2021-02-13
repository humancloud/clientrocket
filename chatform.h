#ifndef CHATFORM_H
#define CHATFORM_H

#include <QWidget>

namespace Ui {
class chatform;
}

class chatform : public QWidget
{
    Q_OBJECT

public:
    explicit chatform(QWidget *parent = nullptr);
    ~chatform();

    void Init();
    void sendmess();
private:
    Ui::chatform *ui;
};

#endif // CHATFORM_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtGui/QFont>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget window;

    int middleWidth = window.size().width() / 2;
    int middleHeight = window.size().height() / 2;

    QPushButton buttonOne("1", &window);
    QPushButton buttonTwo("2", &window);
    QPushButton buttonThree("3", &window);
    QPushButton buttonFour("4", &window);
    QPushButton buttonFive("5", &window);
    QPushButton buttonSix("6", &window);
    QPushButton buttonSeven("7", &window);
    QPushButton buttonEight("8", &window);
    QPushButton buttonNine("9", &window);
    QPushButton buttonZero("0", &window);
    QPushButton buttonDelete("DEL", &window);
    QPushButton buttonClear("AC", &window);
    QPushButton buttonAdd("+", &window);
    QPushButton buttonSub("-", &window);
    QPushButton buttonMul("*", &window);
    QPushButton buttonDiv(":", &window);

    // Column 1

    buttonOne.setGeometry(middleWidth - 120, middleHeight + 160, 50, 40);
    buttonFour.setGeometry(middleWidth - 120, middleHeight + 240, 50, 40);
    buttonSeven.setGeometry(middleWidth - 120, middleHeight + 320, 50, 40);
    buttonClear.setGeometry(middleWidth - 120, middleHeight + 400, 50, 40);

    // Column 2

    buttonTwo.setGeometry(middleWidth - 40, middleHeight + 160, 50, 40);
    buttonFive.setGeometry(middleWidth - 40, middleHeight + 240, 50, 40);
    buttonEight.setGeometry(middleWidth - 40, middleHeight + 320, 50, 40);
    buttonZero.setGeometry(middleWidth - 40, middleHeight + 400, 50, 40);

    // Column 3

    buttonThree.setGeometry(middleWidth + 40, middleHeight + 160, 50, 40);
    buttonSix.setGeometry(middleWidth + 40, middleHeight + 240, 50, 40);
    buttonNine.setGeometry(middleWidth + 40, middleHeight + 320, 50, 40);
    buttonDelete.setGeometry(middleWidth + 40, middleHeight + 400, 50, 40);

    // Column 4

    buttonAdd.setGeometry(middleWidth + 120, middleHeight + 160, 50, 40);
    buttonSub.setGeometry(middleWidth + 120, middleHeight + 240, 50, 40);
    buttonMul.setGeometry(middleWidth + 120, middleHeight + 320, 50, 40);
    buttonDiv.setGeometry(middleWidth + 120, middleHeight + 400, 50, 40);

    // Display

    QLineEdit display("0", &window);
    QFont displayFont = display.font();
    displayFont.setPointSize(24);
    display.setFont(displayFont);
    display.setReadOnly(true);
    display.setGeometry(middleWidth - 120, middleHeight + 60, 290, 60);

    // Appender function

    auto appendDigit = [&](const QString& digit) {
        if (display.text() == "0") {
            display.setText(digit);
        } else {
            display.setText(display.text() + digit);
        }
    };

    QObject::connect(&buttonOne, &QPushButton::clicked, [&]() { appendDigit("1"); });
    QObject::connect(&buttonTwo, &QPushButton::clicked, [&]() { appendDigit("2"); });
    QObject::connect(&buttonThree, &QPushButton::clicked, [&]() { appendDigit("3"); });
    QObject::connect(&buttonFour, &QPushButton::clicked, [&]() { appendDigit("4"); });
    QObject::connect(&buttonFive, &QPushButton::clicked, [&]() { appendDigit("5"); });
    QObject::connect(&buttonSix, &QPushButton::clicked, [&]() { appendDigit("6"); });
    QObject::connect(&buttonSeven, &QPushButton::clicked, [&]() { appendDigit("7"); });
    QObject::connect(&buttonEight, &QPushButton::clicked, [&]() { appendDigit("8"); });
    QObject::connect(&buttonNine, &QPushButton::clicked, [&]() { appendDigit("9"); });
    QObject::connect(&buttonZero, &QPushButton::clicked, [&]() { appendDigit("0"); });
    QObject::connect(&buttonClear, &QPushButton::clicked, [&]() { display.setText("0"); });

    QObject::connect(&buttonDelete, &QPushButton::clicked, [&]()
    {
        QString currentText = display.text();
        if (currentText.length() > 1) {
            currentText.chop(1);
            display.setText(currentText);
        } else if (currentText.length() == 1 && currentText != "0") {
            display.setText("0");
        }
    });

    window.show();

    return app.exec();
}
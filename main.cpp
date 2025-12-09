#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtGui/QFont>

bool endsWithNumber(const QString& text) {
    return (text.endsWith("1") ||
            text.endsWith("2") ||
            text.endsWith("3") ||
            text.endsWith("4") ||
            text.endsWith("5") ||
            text.endsWith("6") ||
            text.endsWith("7") ||
            text.endsWith("8") ||
            text.endsWith("9") ||
            text.endsWith("0"));
}

bool endsWithOperator(const QString& text) {
    return (text.endsWith(" + ") ||
            text.endsWith(" - ") ||
            text.endsWith(" * ") ||
            text.endsWith(" : "));
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget window;

    int middleWidth = window.size().width() / 2;
    int middleHeight = window.size().height() / 2;

    QPushButton one("1", &window);
    QPushButton two("2", &window);
    QPushButton three("3", &window);
    QPushButton four("4", &window);
    QPushButton five("5", &window);
    QPushButton six("6", &window);
    QPushButton seven("7", &window);
    QPushButton eight("8", &window);
    QPushButton nine("9", &window);
    QPushButton zero("0", &window);
    QPushButton deleteButton("DEL", &window);
    QPushButton clear("AC", &window);
    QPushButton addition("+", &window);
    QPushButton subtraction("-", &window);
    QPushButton multiplication("*", &window);
    QPushButton division(":", &window);
    QPushButton equals("=", &window);
    QPushButton openParenthesis("(", &window);
    QPushButton closeParenthesis(")", &window);

    // Column 1

    one.setGeometry(middleWidth - 120, middleHeight + 140, 50, 40);
    four.setGeometry(middleWidth - 120, middleHeight + 200, 50, 40);
    seven.setGeometry(middleWidth - 120, middleHeight + 260, 50, 40);
    clear.setGeometry(middleWidth - 120, middleHeight + 320, 50, 40);

    // Column 2

    two.setGeometry(middleWidth - 40, middleHeight + 140, 50, 40);
    five.setGeometry(middleWidth - 40, middleHeight + 200, 50, 40);
    eight.setGeometry(middleWidth - 40, middleHeight + 260, 50, 40);
    zero.setGeometry(middleWidth - 40, middleHeight + 320, 50, 40);

    // Column 3

    three.setGeometry(middleWidth + 40, middleHeight + 140, 50, 40);
    six.setGeometry(middleWidth + 40, middleHeight + 200, 50, 40);
    nine.setGeometry(middleWidth + 40, middleHeight + 260, 50, 40);
    deleteButton.setGeometry(middleWidth + 40, middleHeight + 320, 50, 40);

    // Column 4

    addition.setGeometry(middleWidth + 120, middleHeight + 140, 50, 40);
    subtraction.setGeometry(middleWidth + 120, middleHeight + 200, 50, 40);
    multiplication.setGeometry(middleWidth + 120, middleHeight + 260, 50, 40);
    division.setGeometry(middleWidth + 120, middleHeight + 320, 50, 40);

    // Final row
    equals.setGeometry(middleWidth + 40, middleHeight + 380, 130, 40);
    openParenthesis.setGeometry(middleWidth - 120, middleHeight + 380, 50, 40);
    closeParenthesis.setGeometry(middleWidth - 40, middleHeight + 380, 50, 40);

    // Display

    QLineEdit display("", &window);
    QFont displayFont = display.font();
    displayFont.setPointSize(24);
    display.setFont(displayFont);
    display.setReadOnly(true);
    display.setGeometry(middleWidth - 120, middleHeight + 60, 290, 60);

    // Appender function

    auto appendDigit = [&](const QString& digit) {
        if (display.text() == "") {
            display.setText(digit);
        } else {
            display.setText(display.text() + digit);
        }
    };

    // Logic

    int currCounter = 0;

    // Number buttons

    QObject::connect(&one, &QPushButton::clicked, [&]()
    {
        appendDigit("1");
        currCounter++;
    });
    QObject::connect(&two, &QPushButton::clicked, [&]()
    {
        appendDigit("2");
        currCounter++;
    });
    QObject::connect(&three, &QPushButton::clicked, [&]()
    {
        appendDigit("3");
        currCounter++;
    });
    QObject::connect(&four, &QPushButton::clicked, [&]()
    {
        appendDigit("4");
        currCounter++;
    });
    QObject::connect(&five, &QPushButton::clicked, [&]()
    {
        appendDigit("5");
        currCounter++;
    });
    QObject::connect(&six, &QPushButton::clicked, [&]()
    {
        appendDigit("6");
        currCounter++;
    });
    QObject::connect(&seven, &QPushButton::clicked, [&]()
    {
        appendDigit("7");
        currCounter++;
    });
    QObject::connect(&eight, &QPushButton::clicked, [&]()
    {
        appendDigit("8");
        currCounter++;
    });
    QObject::connect(&nine, &QPushButton::clicked, [&]()
    {
        appendDigit("9");
        currCounter++;
    });
    QObject::connect(&zero, &QPushButton::clicked, [&]()
    {
        appendDigit("0");
        currCounter++;
    });

    // Equation buttons

    QObject::connect(&addition, &QPushButton::clicked, [&]()
    {
        if (endsWithNumber(display.text())) {
            appendDigit(" + ");
            currCounter += 3;
        }
    });
    QObject::connect(&subtraction, &QPushButton::clicked, [&]()
    {
        if (endsWithNumber(display.text())) {
            appendDigit(" - ");
            currCounter += 3;
        }
    });
    QObject::connect(&multiplication, &QPushButton::clicked, [&]()
    {
        if (endsWithNumber(display.text())) {
            appendDigit(" * ");
            currCounter += 3;
        }
    });
    QObject::connect(&division, &QPushButton::clicked, [&]()
    {
        if (endsWithNumber(display.text())) {
            appendDigit(" : ");
            currCounter += 3;
        }
    });

    // Parenthesis buttons

    int openCounter = 0;
    int closedCounter = 0;
    QObject::connect(&openParenthesis, &QPushButton::clicked, [&]()
    {
        if (endsWithOperator(display.text()) ||display.text() == "") {
            appendDigit("(");
            openCounter++;
        }
    });
    QObject::connect(&closeParenthesis, &QPushButton::clicked, [&]()
    {
        if (openCounter > closedCounter && endsWithNumber(display.text())) {
            appendDigit(")");
            closedCounter++;
        }
    });

    // Clear and delete buttons

    QObject::connect(&clear, &QPushButton::clicked, [&]() { display.setText("0"); });

    QObject::connect(&deleteButton, &QPushButton::clicked, [&]()
    {
        QString currentText = display.text();
        if (currentText.length() > 1) {
            currentText.chop(1);
            display.setText(currentText);
        } else if (currentText.length() == 1 && currentText != "0") {
            display.setText("");
        }
    });

    // Equal button

    QObject::connect(&equals, &QPushButton::clicked, [&]()
    {
        QString expression = display.text();
    });

    window.show();

    return app.exec();
}
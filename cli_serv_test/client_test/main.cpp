#include <QCoreApplication>
#include "client.h"
#include <unistd.h>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>

QStringList readFileToArray(const QString& filename) {
    QFile file(filename);
    QStringList lines;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            lines.append(line);
        }
        file.close();
    } else {
        qDebug() << "Unable to open file.";
    }

    return lines;
}

void writeArrayToFile(const QStringList& data, const QString& filename) {
    QFile file(filename);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        for (const QString& line : data) {
            out << line << "\n";
        }

        file.close();
        qDebug() << "File saved successfully.";
    } else {
        qDebug() << "Unable to open file for writing.";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList data = readFileToArray("input.txt");
    pid_t pid = fork();
    if (pid != 0)
    {
        Client client_sender;
        QStringList data = readFileToArray("input.txt");
        for (const QString& line : data)
        {
            client_sender.SendToServer(line);
        }
        sleep(1);
        exit(0);
    }
    else
    {
        Client client_reciever;
        sleep(1);
        writeArrayToFile(data, "output.txt");
        exit(0);
    }
    return a.exec();
}

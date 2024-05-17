#include "include/incsv/server.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Server server;
    // server.listen();

    return app.exec();
}

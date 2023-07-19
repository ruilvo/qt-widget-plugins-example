#include "app.hpp"
#include "main_window.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication qapp(argc, argv);

    qtwpe::App app{};
    qtwpe::MainWindow window{&app};

    window.show();

    // NOLINTNEXTLINE(readability-static-accessed-through-instance)
    qapp.exec();
}

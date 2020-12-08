
#include <Qt>
#include <QApplication>

int main(int argc, char** argv) {
  QCoreApplication::addLibraryPath("../lib");
  QApplication app(argc,argv);

  return app.exec();
}



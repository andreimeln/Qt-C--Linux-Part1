#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

namespace MYAPP {

class Application : public QApplication {

  Q_OBJECT

  private:
    Application();
    Application(const Application &);
    const Application & operator = (const Application &);
 
  public:
    Application(int argc, char *argv[]);
    virtual ~Application(void) {};

    void setup_language(const QString & lcode);

};

} // namespace MYAPP

#endif // APPLICATION_H

#include <QTimer>

class Executor {

public:

  QTimer *timer;

  void startTimer(int interval);

  void makeStrategy();

  void scheduleTask();

  void sendDirective();

  // 设计文档中的类转换成功能
  void manageScene();

  void dispatchDirective();

  void collectResult();

};

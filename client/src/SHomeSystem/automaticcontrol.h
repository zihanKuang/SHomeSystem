#ifndef AUTOMATICCONTROL_H
#define AUTOMATICCONTROL_H

class AutomaticControl {

public:
  void makeStrategy();

  void scheduleTask();

  void sendDirective();

  //设计文档里的类转为的功能
  void manageScene();

  void dispatchDirective();

  void collectResult();

};

#endif

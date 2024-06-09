#ifndef CLASSES_COMMON_WIDGET_H_
#define CLASSES_COMMON_WIDGET_H_

#include <memory>

class Widget {
 public:
  explicit Widget(int n);
  Widget();
  ~Widget();

  Widget(const Widget& another) = delete;
  Widget& operator=(const Widget& another) = delete;

  Widget(Widget&& another);
  Widget& operator=(Widget&& another);

  void Draw() const;
  void Draw();
  bool Shown() const { return true; }

 private:
  // PImpl idiom: pointer to implementation, opaque pointer
  // compile time encapsulation
  // hide implementation details, reduce coupling, separate interfaces
  class Impl;
  std::unique_ptr<Impl> pimpl_;
};

#endif  // CLASSES_COMMON_WIDGET_H_

#include "classes/common/widget.h"

#include <iostream>

class Widget::Impl {
 public:
  Impl(int n);

  void Draw(const Widget& widget) const;
  void Draw(const Widget& widget);

 private:
  int n_;
};

Widget::Impl::Impl(int n) : n_(n) {}

void Widget::Impl::Draw(const Widget& widget) const {
  if (widget.Shown()) {
    std::cout << "Drawing a const widget " << n_ << std::endl;
  }
}

void Widget::Impl::Draw(const Widget& widget) {
  if (widget.Shown()) {
    std::cout << "Drawing a non-const widget " << n_ << std::endl;
  }
}

Widget::Widget(int n) : pimpl_(std::make_unique<Impl>(n)) {}

Widget::Widget() = default;

Widget::~Widget() = default;

Widget::Widget(Widget&& another) = default;

Widget& Widget::operator=(Widget&& another) = default;

void Widget::Draw() const { pimpl_->Draw(*this); }

void Widget::Draw() { pimpl_->Draw(*this); }

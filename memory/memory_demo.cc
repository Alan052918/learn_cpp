#include <iostream>
#include <memory>

#include "classes/common/file_handle.h"
#include "classes/common/person.h"
#include "meta/common/demo_wrapper.h"

void UniquePointerDemo() {
  demo::EnterScope("UniquePointerDemo");

  std::unique_ptr<FileHandle> uptr = std::make_unique<FileHandle>("myfile.txt");
  uptr->Append("Hello, World!");
  std::cout << *uptr;

  std::unique_ptr<FileHandle> uptr2 = std::move(uptr);
  std::cout << (uptr ? "uptr is not null" : "uptr is null") << std::endl;
  std::cout << "uptr: " << uptr.get() << std::endl;
  std::cout << "uptr2: " << uptr2.get() << std::endl;

  uptr2->Append("I'm Junda.");
  std::cout << *uptr2;

  demo::ExitScope("UniquePointerDemo");
}

void SharedPointerDemo() {
  demo::EnterScope("SharedPointerDemo");

  Person alice("Alice");
  std::cout << "alice named object: " << alice.name() << std::endl << std::endl;

  auto shared_alice = std::make_shared<Person>(alice);
  std::cout << "shared_alice by copying to make_shared (new Person object): "
            << shared_alice->name() << " use_count=" << shared_alice.use_count()
            << " unique=" << shared_alice.unique() << std::endl
            << std::endl;

  auto shared_alice2 = std::make_shared<Person>("Alice");
  std::cout
      << "shared_alice2 by passing args to make_shared (new Person object): "
      << shared_alice2->name() << " use_count=" << shared_alice.use_count()
      << " unique=" << shared_alice.unique() << std::endl
      << std::endl;

  auto shared_alice3(shared_alice);
  std::cout << "shared_alice3 by shared_ptr copy constructor: "
            << shared_alice3->name()
            << " use_count=" << shared_alice.use_count()
            << " unique=" << shared_alice.unique() << std::endl;

  auto shared_alice4 = shared_alice;
  std::cout << "shared_alice4 by shared_ptr copy assignment: "
            << shared_alice4->name()
            << " use_count=" << shared_alice.use_count()
            << " unique=" << shared_alice.unique() << std::endl;

  // TODO: how does owner_before work?
  std::cout << "shared_alice > shared_alice4: "
            << (shared_alice > shared_alice4) << std::endl;
  std::cout << "shared_alice.owner_before(shared_alice4): "
            << shared_alice.owner_before(shared_alice4) << std::endl
            << std::endl;

  auto shared_alice5(std::move(shared_alice));
  std::cout << "shared_alice5 by shared_ptr move constructor: "
            << shared_alice5->name()
            << " use_count=" << shared_alice.use_count()
            << " unique=" << shared_alice.unique() << std::endl
            << std::endl;

  auto shared_alice6 = std::move(shared_alice2);
  std::cout << "shared_alice6 by shared_ptr move assignment: "
            << shared_alice6->name()
            << " use_count=" << shared_alice.use_count()
            << " unique=" << shared_alice.unique() << std::endl;

  demo::ExitScope("SharedPointerDemo");
}

void WeakPointerDemo() {
  demo::EnterScope("WeakPointerDemo");

  auto shared_alice = std::make_shared<Person>("Alice");

  auto weak_alice = std::weak_ptr<Person>(shared_alice);
  std::cout << "weak_alice by named shared_alice: " << weak_alice.lock()->name()
            << std::endl;

  // dangling pointer alert !!!
  // std::make_shared() returns a temporary object released after the following
  // line, then weak_alice2 manages no object, accessing it might lead to
  // segfault
  auto weak_alice2 = std::weak_ptr<Person>(std::make_shared<Person>("Alice"));
  std::cout << "weak_alice2.expired(): " << weak_alice2.expired() << std::endl;
  if (auto temp_shared_alice = weak_alice2.lock()) {
    std::cout << temp_shared_alice->name() << std::endl;
  } else {
    std::cout << "weak_alice2 is a dangling pointer" << std::endl;
  }

  demo::ExitScope("WeakPointerDemo");
}

int main(int argc, char const *argv[]) {
  UniquePointerDemo();
  SharedPointerDemo();
  WeakPointerDemo();
}

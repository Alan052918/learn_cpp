#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

// RAII style file handler container
class File {
  std::fstream file_;

 public:
  File(const std::string& filename)
      : file_(std::fstream(filename,
                           std::ios::in | std::ios::out | std::ios::trunc)) {
    if (!file_.is_open()) throw std::runtime_error("Error opening file");
    std::cout << "**File constructor: file opened" << std::endl;
  }

  ~File() {
    file_.close();
    std::cout << "**File destructor: file closed" << std::endl;
  }

  void printAllLines(std::ostream& stream) {
    file_.seekg(0, std::ios::beg);

    std::cout << "+-- File Content --+" << std::endl;
    for (std::string line; std::getline(file_, line);)
      stream << line << std::endl;
    std::cout << "+-- End of File --+" << std::endl;

    file_.clear();
  }

  void append(const std::string& content) {
    file_.seekp(0, std::ios::end);
    file_ << content << std::endl;
  }
};

void uniquePointerDemo() {
  std::cout << std::endl << "-- unique_ptr demo --" << std::endl;

  std::unique_ptr<File> uptr(new File("myfile.txt"));
  uptr->append("Hello, World!");
  uptr->printAllLines(std::cout);

  std::unique_ptr<File> uptr2 = std::move(uptr);
  std::cout << (uptr ? "uptr is not null" : "uptr is null") << std::endl;
  std::cout << "uptr: " << uptr.get() << std::endl;
  std::cout << "uptr2: " << uptr2.get() << std::endl;

  uptr2->append("I'm Junda.");
  uptr2->printAllLines(std::cout);
}

void sharedPointerDemo() {
  std::cout << std::endl << "-- shared_ptr demo --" << std::endl;

  // make_shared allocate memory only once, way faster
  std::shared_ptr<File> sptr = std::make_shared<File>("myfile.txt");
  // std::shared_ptr<File> sptr(new File("myfile.txt"));

  std::cout << "sptr use_count: " << sptr.use_count() << std::endl;
  {
    std::shared_ptr<File> sptr2 = sptr;
    std::cout << "sptr2 use_count: " << sptr2.use_count() << std::endl;

    sptr->append("Hello, World!");
    sptr2->append("It's Junda.");
    sptr->printAllLines(std::cout);
  }
  std::cout << "sptr use_count: " << sptr.use_count() << std::endl;
}

class Course;
class Student;

class Course : public std::enable_shared_from_this<Course> {
  std::string name_;
  std::vector<std::weak_ptr<Student>> students_;

 public:
  Course(const std::string& name) : name_(name) {
    std::cout << "new course: " << name_ << std::endl;
  }

  ~Course() { std::cout << "delete course: " << name_ << std::endl; }

  const std::string& name() const { return name_; }

  void AddStudent(const std::shared_ptr<Student>& student);

  const std::vector<std::weak_ptr<Student>>& students() const {
    return students_;
  }
};

class Student : public std::enable_shared_from_this<Student> {
  std::string name_;
  std::vector<std::weak_ptr<Course>> courses_;

 public:
  Student(const std::string& name) : name_(name) {
    std::cout << "new student: " << name_ << std::endl;
  }

  ~Student() { std::cout << "delete student: " << name_ << std::endl; }

  const std::string& name() const { return name_; }

  void AddCourse(const std::shared_ptr<Course>& course);

  const std::vector<std::weak_ptr<Course>>& courses() const { return courses_; }
};

void Course::AddStudent(const std::shared_ptr<Student>& student) {
  if (std::find_if(students_.begin(), students_.end(),
                   [&student](const std::weak_ptr<Student>& weak_student) {
                     if (auto sptr = weak_student.lock())
                       return student == sptr;
                     return false;
                   }) == students_.end()) {
    students_.push_back(student);
    student->AddCourse(shared_from_this());
  }
}

void Student::AddCourse(const std::shared_ptr<Course>& course) {
  if (std::find_if(courses_.begin(), courses_.end(),
                   [&course](const std::weak_ptr<Course>& weak_course) {
                     if (auto sptr = weak_course.lock()) return course == sptr;
                     return false;
                   }) == courses_.end()) {
    courses_.push_back(course);
    course->AddStudent(shared_from_this());
  }
}

void weakPointerDemo() {
  std::cout << std::endl << "-- weak_ptr demo --" << std::endl;

  std::shared_ptr<Course> math(new Course("Math"));
  std::shared_ptr<Course> physics(new Course("Physics"));

  std::shared_ptr<Student> john(new Student("John"));
  std::shared_ptr<Student> jane(new Student("Jane"));

  john->AddCourse(math);
  john->AddCourse(physics);
  jane->AddCourse(math);
  std::cout << std::boolalpha << "jane's first course expired: "
            << jane->courses().front().expired()
            << ", use_count: " << jane->courses().front().use_count()
            << std::endl;

  std::cout << john->name() << " has courses: ";
  auto john_courses = john->courses();
  std::for_each(john_courses.begin(), john_courses.end(),
                [](std::weak_ptr<Course> course) {
                  std::cout << course.lock()->name() << " ";
                });
  std::cout << std::endl;

  std::cout << jane->name() << " has courses: ";
  auto jane_courses = jane->courses();
  std::for_each(jane_courses.begin(), jane_courses.end(),
                [](std::weak_ptr<Course> course) {
                  std::cout << course.lock()->name() << " ";
                });
  std::cout << std::endl;

  std::cout << math->name() << " has students: ";
  auto math_students = math->students();
  std::for_each(math_students.begin(), math_students.end(),
                [](std::weak_ptr<Student> student) {
                  std::cout << student.lock()->name() << " ";
                });
  std::cout << std::endl;

  std::cout << physics->name() << " has students: ";
  auto physics_students = physics->students();
  std::for_each(physics_students.begin(), physics_students.end(),
                [](std::weak_ptr<Student> student) {
                  std::cout << student.lock()->name() << " ";
                });
  std::cout << std::endl;
}

int main(int argc, char const* argv[]) {
  uniquePointerDemo();
  sharedPointerDemo();
  weakPointerDemo();
}

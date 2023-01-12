# learn_cpp

This is a repository for my C++ learning journey. Packages can be build with [Bazel](https://bazel.build). Content loosely follows [cppreference.com](https://en.cppreference.com/w/cpp).

```bash
# build and run meta (metaprogramming) package
bazel run //meta:meta
```

```txt
INFO: Analyzed target //meta:meta (0 packages loaded, 0 targets configured).
INFO: Found 1 target...
Target //meta:meta up-to-date:
  bazel-bin/meta/meta
INFO: Elapsed time: 0.494s, Critical Path: 0.40s
INFO: 3 processes: 1 internal, 2 darwin-sandbox.
INFO: Build completed successfully, 3 total actions
INFO: Running command line: bazel-bin/meta/meta

--- MetaDemo ---
[Person] constructor: creating Alice
alice: Person {name='Alice', age=0 publications={ }}

[Person] copy constructor: copying Alice
shared_alice: Person {name='Alice', age=0 publications={ }}

back of people: Person {name='Alice', age=0 publications={ }}

[Person] constructor: creating Bob
back of people: Person {name='Bob', age=0 publications={ }}

people_vec { Person {name='Alice', age=0 publications={ }} Person {name='Bob', age=0 publications={ }} }
vec { one two three }
list { 1 2 3 }

--- MetaDemo exit scope ---
[Person] destructor: deleting Bob
[Person] destructor: deleting Alice
[Person] destructor: deleting Alice
```

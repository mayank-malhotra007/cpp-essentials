# STL- Standard Template Library

It is a C++ library, that provides collection of
- containers
- algorithms
- iterators

## Need of STL?

- Code reusability: instead of writing the data structure and algorithms ourselves from scratch, one can use the STL components
- Efficiency: STL implementations are highly optimized
- Consistency: STL offer a consistent interface and design pattern
- Generic programming: build on templates, hence user can use any data type

## Macros

Macros are preprocesspor directives - instructions that run before the compiler compiles the C++ code.
They are created with #define and are replaced literally in the code by the preprocessor.

Macros dont have a type definition, thus can be used for generic programming.

### Problem with Macros
- no type safety
- debugging is harder 
- no scope control, as macros are global
- unexpected behaviour

### Preferred

- using const modifier
- use templates for generic programming

## Templates

Templates are a feature of C++, which provide generic programming with type safety.
Templates serve as a blueprint for a class or a function.

### Advantages of templates

- compiler checks for type safety
- scoped to function or class
- compiler gives meaningful errors
- no unpredictable behaviour

## Containers

Containers are class templates that hold object of a specific type.

- saves time, ready to use data structures
- consistency
- make use of STL itertors and algorithms

### Categories of Containers

#### Sequence Containers
- std::vector
- std::deque
- std::list
- std::forward_list
- std::array

#### Associative Containers
- std::set
- std::map
- std::multiset
- std::multimap

#### Container Adaptors
- std::stack
- std::queue
- std::priority_queue

##### Vectors vs Arrays

- vectors are dynamic in nature, can grow and shrink at runtime, arrays can be static where the size is fixed at the compile time or dynamic. 
- vectors are always on the heap, static arrays on stack and dynamic arrays on the heap.
- vectors provide bounds checking using .at(), arrays do not
- vector are a part of the STL, hence algorithms such as resize(), etc are available, not for arrays.
- vectors provide autotic memory management, if using dynamic arrays using new[], programmer needs to take care of the pointer memory.
- use arrays when at compile time the size is knows, use vectors for flexibility and safety
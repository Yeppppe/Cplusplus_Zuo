ThreadPool
==========

A simple C++11 Thread Pool implementation.

Basic usage:

```c++
// create thread pool with 4 worker threads
ThreadPool pool(4);

// enqueue and store future
auto result = pool.enqueue([](int answer) { return answer; }, 42);

// get result from future
std::cout << result.get() << std::endl;

```



thread类

```C++
thread(f&& f, Arg&&... args);
```

thread对象只能够移动赋值或移动构造，为了确保每一个thread对象都是唯一的

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <mutex>
#include <string>
#include <iostream>
#include <thread>

namespace creational
{
      namespace singleton
      {
          /**
            * The singleton class defines the `GetInstance` method that serves as an
            * alternative to constructor and lets clients access the same instance of this
            * class over and over.
            */
          class singleton
          {

            /**
            * The singleton's constructor/destructor should always be private to
            * prevent direct construction/desctruction calls with the `new`/`delete`
            * operator.
            */
          private:
              static singleton *pinstance_;
              static std::mutex mutex_;

          protected:
              singleton(const std::string value) : value_(value)
              {
              }
              ~singleton() {}
              std::string value_;
              class gargc
              {
              public:
                ~gargc()
                {
                  if (singleton::pinstance_)
                  {
                    delete singleton::pinstance_;
                    singleton::pinstance_ = 0;
                    std::cout << "delete singleton::pinstance_" << std::endl;
                  }
                  
                }
              };
              static gargc gc;

            public:
              /**
              * singletons should not be cloneable.
              */
              singleton(singleton &other) = delete;
              /**
                * singletons should not be assignable.
                */
              void operator=(const singleton &) = delete;
              /**
                * This is the static method that controls the access to the singleton
                * instance. On the first run, it creates a singleton object and places it
                * into the static field. On subsequent runs, it returns the client existing
                * object stored in the static field.
                */

              static singleton *GetInstance(const std::string &value);
              /**
                * Finally, any singleton should define some business logic, which can be
                * executed on its instance.
                */
              void SomeBusinessLogic()
              {
                  // ...
              }

              std::string value() const
              {
                  return value_;
              }
          };

          /**
            * Static methods should be defined outside the class.
            */

          singleton *singleton::pinstance_{nullptr};
          singleton::gargc singleton::gc;
          std::mutex singleton::mutex_;

          /**
            * The first time we call GetInstance we will lock the storage location
            * and then we make sure again that the variable is null and then we
            * set the value. RU:
            */
          singleton *singleton::GetInstance(const std::string &value)
          {
              if(pinstance_ == nullptr)
              {
                  std::lock_guard<std::mutex> lock(mutex_);
                  if (pinstance_ == nullptr)
                  {
                    pinstance_ = new singleton(value);
                  }
              }
              
              return pinstance_;
          }

          void ThreadFoo()
          {
              // Following code emulates slow initialization.
              std::this_thread::sleep_for(std::chrono::milliseconds(1000));
              singleton *singleton = singleton::GetInstance("FOO");
              std::cout << singleton->value() << "\n";
          }

          void ThreadBar()
          {
              // Following code emulates slow initialization.
              std::this_thread::sleep_for(std::chrono::milliseconds(1000));
              singleton *singleton = singleton::GetInstance("BAR");
              std::cout << singleton->value() << "\n";
          }

          int main()
          {
              std::cout << "If you see the same value, then singleton was reused (yay!\n"
                        << "If you see different values, then 2 singletons were created (booo!!)\n\n"
                        << "RESULT:\n";
              std::thread t1(ThreadFoo);
              std::thread t2(ThreadBar);
              t1.join();
              t2.join();

              return 0;
          }
      } // namespace creational
         
} // namespace design

     

#endif
#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <iostream>
#include <string>
#include <list>

namespace behavioral
{
    namespace observer
    {
        class i_observer {
        public:
            virtual ~i_observer(){};
            virtual void update(const std::string &message_from_subject) = 0;
        };

        class i_subject{
        public:
            virtual ~i_subject(){};
            virtual void attach(i_observer *observer) = 0;
            virtual void detach(i_observer *observer) = 0;
            virtual void notify() = 0;
        };


        class subject : public i_subject{
        public:
            virtual ~subject(){
                std::cout << "goodby, I was the subject.\n";
            }

            void attach(i_observer *observer) override {
                list_observer_.push_back(observer);
            }

            void detach(i_observer *observer) override {
                list_observer_.remove(observer);
            }

            void notify() override {
                std::list<i_observer *>::iterator iterator = list_observer_.begin();
                how_many_observer();
                while (iterator != list_observer_.end())
                {
                    (*iterator)->update(message_);
                    ++iterator;
                }
                
            }

            void create_message(std::string message = "empty"){
                this->message_ = message;
                notify();
            }
            
            void how_many_observer() {
                std::cout << "There are " << list_observer_.size() << " observers in the list\n";
            }

            void some_business_logic() {
                this->message_ = "change message ";
                notify();
                std::cout << "I'm about to do some thing important\n";
            }


        private:
            std::list<i_observer *> list_observer_;
            std::string message_;
        };


        class observer : public i_observer{
        public:
           observer(subject &subject) : subject_(subject) {
               this->subject_.attach(this);
               std::cout << "Hi, I'm the observer \"" << ++observer::static_number_ << "\".\n";
               this->number_ = observer::static_number_;
           }

           virtual ~observer() {
               std::cout << "Goodbye, I was the observer \"" << this->number_ << "\".\n";
           }

           void update(const std::string &message_from_subject) override {
               message_from_subject_ = message_from_subject;
               print_info();
           }

           void remove_me_from_subject() {
               subject_.detach(this);
               std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
           }

           void print_info() {
               std::cout << "Observer \"" << this->number_ << "\": a new message is available -->"
                    << this->message_from_subject_ << "\n";
           }

        private: 
            std::string message_from_subject_;
            subject &subject_;
            static int static_number_;
            int number_;
        };

        int observer::static_number_ = 0;

        void client_code() {
            subject *sub = new subject();
            observer *observer1 = new observer(*sub);
            observer *observer2 = new observer(*sub);
            observer *observer3 = new observer(*sub);
            observer *observer4;
            observer *observer5;

            sub->create_message("Hello World!: D");
            observer3->remove_me_from_subject();

            sub->create_message("The weather is hot today! :p");
            observer4 = new observer(*sub);

            observer2->remove_me_from_subject();
            observer5 = new observer(*sub);

            sub->create_message("My new car is great! ;)");
            observer5->remove_me_from_subject();

            observer4->remove_me_from_subject();
            observer1->remove_me_from_subject();

            delete observer5;
            delete observer4;
            delete observer3;
            delete observer2;
            delete observer1;
            delete sub;
        }

    } // namespace observer
      
} // namespace behaviour


  

#endif // OBSERVER_HPP
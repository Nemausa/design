#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

using namespace std;

namespace other
{
    namespace sw
    {
        void Zero() { printf("Zero\n"); }
        void One() { printf("One\n"); }
        void Two() { printf("Two\n"); }
        void Three() { printf("Three\n"); }

        string prompt()
        {
            printf("Enter number from 0 to 3 or q to quit:\n");
            string line;
            getline(cin, line);

            return line;
        }

        int jumptable()
        {
            unordered_map<string, void (*)()> map;

            map["0"] = Zero;
            map["1"] = One;
            map["2"] = Two;
            map["3"] = Three;

            while (true)
            {
                string c = prompt();
                if (c == "q")
                    break;

                map[c]();
            }
            return 0;
        }

        //use polymorphism and call a virtual function instead
        class state
        {
            public:
                state() {}
                virtual ~state() {}
                virtual void show_message() = 0;
        };

        class state_one : public state
        {
            public:
                state_one() { std::cout << "state_one()" << std::endl; }
                ~state_one() { std::cout << " ~state_one()" << std::endl; }
                virtual void show_message()
                {
                    std::cout << "state_one::show_message" << std::endl;
                }
        };

        class state_two : public state
        {
        public:
            state_two() { std::cout << "state_two()" << std::endl; }
            ~state_two() { std::cout << "~state_two()" << std::endl; }
            virtual void show_message()
            {
                std::cout << "state_two::show_message" << std::endl;
            }
        };

        int main()
        {
            std::shared_ptr<state> one = std::make_shared<state_one>();
            one->show_message();
            one = std::make_shared<state_two>();
            one->show_message();

            return 0;
        }





    } // namespace sw
    
} // namespace other


#endif
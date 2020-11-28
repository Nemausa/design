#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include <iostream>
#include <vector>

namespace structural
{
    namespace composite
    {

        class component
        {
        public:
            virtual void terverse() = 0;
        };

        class leaf : public component
        {
        public:
            leaf(int val)
            {
                value_ = val;
            }

            void terverse()
            {
                std::cout << value_ << ' ';
            }

        private:
            int value_;
        };

        class composite : public component
        {
        public:
            void add(component *ele)
            {
                children_.push_back(ele);
            }

            void terverse()
            {
                for (auto child : children_)
                    child->terverse();
            }

        private:
            std::vector<component *> children_;
        };

        int main() {
            composite containers[4];
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 3; j++)
                    containers[i].add(new leaf(i * 3 + j));

            for (int i = 1; i < 4; i++)
                containers[0].add(&(containers[i]));

            for (int i = 0; i < 4; i++) {
                containers[i].terverse();
                std::cout << std::endl;
            }
            return 0;
        }
    } // namespace composite
    
} // namespace structural



#endif // COMPOSITE_HPP
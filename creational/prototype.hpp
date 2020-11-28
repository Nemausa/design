#ifndef PROTOTYPE_HPP
#define PROTOTYPE_HPP


// this is not a good example 

#include <iostream>

namespace creational{
    namespace prototype{

        enum ImageType
        {
            LSAT,
            SPOT
        };

        class image{
        public:
            virtual void draw() = 0;
            static image *find_and_clone(ImageType);

        protected:
            virtual ImageType return_type() = 0;
            virtual image *clone() = 0;

            static void add_prototype(image *image){
                prototype_[next_slot_++] = image;
            }
        private:
            static image *prototype_[10];
            static int next_slot_;
        };

        image *image::prototype_[];
        int image::next_slot_;

        image *image::find_and_clone(ImageType type){
            for (int i = 0; i < next_slot_; i++)
                if (prototype_[i]->return_type() == type)
                    return prototype_[i]->clone();
            return NULL;
        }

        class land_sta_image: public image {
        public:
            ImageType return_type()
            {
                return LSAT;
            }

            void draw() {
                std::cout << "land_sta_image::draw " << id_ << std::endl;
            }

            image *clone() {
                return new land_sta_image(1);
            }
        protected:
            land_sta_image(int dummy){
                id_ = count_++;
            }
        private:
            static land_sta_image land_sta_image_;
            land_sta_image(){
                add_prototype(this);
            }

            int id_;
            static int count_;
        };

        land_sta_image land_sta_image::land_sta_image_;
        int land_sta_image::count_ = 1;

        class spot_image : public image {
        public:
            ImageType return_type() {
                return SPOT;
            }
            
            void draw() {
                std::cout << "spot_image::draw " << id_ << std::endl;
            }
            
            image *clone() {
                return new spot_image(1);
            }
        protected:
            spot_image(int dummy) {
                id_ = count_++;
            }
        private:
            spot_image() {
                add_prototype(this);
            }

            static spot_image spot_image_;
            int id_;
            static int count_;
        };

        spot_image spot_image::spot_image_;
        int spot_image::count_ = 1;

        // Simulated stream of creation requests
        const int NUM_IMAGES = 8;
        ImageType input[NUM_IMAGES] =
            {
                LSAT, LSAT, LSAT, SPOT, LSAT, SPOT, SPOT, LSAT
            };

        int main()
        {
            image *images[NUM_IMAGES];

            // Given an image type, find the right prototype, and return a clone
            for (int i = 0; i < NUM_IMAGES; i++)
                images[i] = image::find_and_clone(input[i]);

            // Demonstrate that correct image objects have been cloned
            for (int i = 0; i < NUM_IMAGES; i++)
                images[i]->draw();

            // Free the dynamic memory
            for (int i = 0; i < NUM_IMAGES; i++)
                delete images[i];

            return 0;
        }

    } // namespace prototype
    
} // namespace creational



#endif // PROTOOTYPE_HPP

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>

struct Data
{
    unsigned int value;
};

class Serializer
{
    public:
        Serializer();
        Serializer(Serializer const & other);
		Serializer & operator=(Serializer const & other); 
        virtual ~Serializer() = 0;

        static uintptr_t    serialize   (Data*      ptr);
        static Data*        deserialize (uintptr_t  raw);
};

#endif
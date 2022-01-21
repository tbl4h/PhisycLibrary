#include <iostream>
#include <type_traits>
enum AXIS
{   
    default_type = -1,
    x = 0,
    y = 1,
    z = 2
};
template<AXIS axi>
class unit_vector
{
public: 

    unit_vector(){
        this.axi_ = axi;
    }
    
    consteval void operator=(const unit_vector& other){
        this->length = std::move(other.length);
        this->direction = std::move(other.direction);        
        this->axi = std::move(other.axi);
    }
private:
    double length_{1.0};
    double direction_{0.0};
    AXIS axi_;
};

/*
template <typename lengthType, typename directionType>
class vector_2d
{
    */
    /*
    static_assert(std::is_arithmetic<lengthType>::value , "lengthType is not arithmetic type");
    static_assert(std::is_arithmetic<directionType>::value , "directionType is not arithmetic type");
    static_assert(std::is_trivially_constructible<lengthType, int>::value);
    static_assert(std::is_trivially_constructible<directionType, int>::value);
    static_assert(std::is_trivially_constructible<lengthType, double>::value);
    static_assert(std::is_trivially_constructible<directionType, double>::value);
    */
/*
private:
    lengthType length;
    directionType direction;

public:
    vector_2d()
    {
        
    };
    vector_2d(int Length, int Direction);
    ~vector_2d()
    {
    }
};
*/

unit_vector<x> x_vec;
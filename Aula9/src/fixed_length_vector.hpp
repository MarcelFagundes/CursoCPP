#ifndef DATA_STRUCTUTURES_FIXED_LENGTH_VECTOR
#define DATA_STRUCTUTURES_FIXED_LENGTH_VECTOR

#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace data_structures {

class DSError: public std::runtime_error {
public:
  using std::runtime_error::runtime_error;
};

class OutOfBoundsError: public DSError {
public:
  using DSError::DSError;
};

template <typename T>
class FLV {
public:
  FLV(int size): 
    contents{new T[size]},
    size_{size} 
  {}

  ~FLV() { 
    delete[] contents; 
  }

  // lvalue reference
  FLV(FLV const &other): 
    contents{new T[other.size_]}, 
    size_{other.size_} 
  {
    std::cout << "Yay! Copied. \n";
    for (auto i = 0; i < size_; ++i) {
      contents[i] = other[i];
    }
  }

  // rvalue reference
  FLV(FLV &&other): 
    contents{other.contents},
    size_{other.size_} 
  {
    std::cout << "Moved! \n";
    other.contents = nullptr;
  }

  FLV &operator=(FLV const &outher) {
    auto aux = outher;
    this->swap(aux);
    return *this;
  }

  FLV &operator=(FLV &&outher) {
    auto aux = std::move(outher);
    this->swap(aux);
    return *this;
  }

  T& operator[](int i) 
  { 
    return contents[i]; 
  }

  T& at(int i) {
    bounds_check(i);    
    return contents[i];
  }

  T const& at(int i) const {
    bounds_check(i);    
    return contents[i];
    }

    void swap(FLV& other) {
      using std::swap;

      swap(contents, other.contents);
      swap(size_, other.size_);
    }

  T const& operator[](int i) const 
  { 
    return contents[i]; 
  }

  private:
   void bounds_check(int i) const
   {
      if (i < 0 or i >= size_) {
        throw OutOfBoundsError("Access out of bounds");
      }
    }

   
   T* contents;
   int size_;
  };
}

#endif // !DATA_STRUCTUTURES_FIXED_LENGTH_VECTOR

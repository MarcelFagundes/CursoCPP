#ifndef DATA_STRUCTUTURES_FIXED_LENGTH_VECTOR
#define DATA_STRUCTUTURES_FIXED_LENGTH_VECTOR

#include <algorithm>
#include <iostream>

namespace data_structures {

template<typename T>
class FLV {
public:
  FLV(int size):
    contents{new T[size]},
    size_{size}
  {} 
  
  ~FLV()
  {
    delete[] contents;
  }

  // lvalue reference
  FLV(FLV const& other):
    contents{new T[other.size_]},
    size_{other.size_}
  {
    std::cout << "Yay! Copied. \n";
    for (auto i=0; i < size_; ++i) {
      contents[i] = other[i];
    } 
  }

  //rvalue reference
  FLV(FLV&& other):  
    contents{other.contents},
    size_{other.size_}
  {
    std::cout << "Moved! \n";
    other.contents = nullptr;
  }

  FLV& operator=(FLV const& outher)
  {
    auto aux = outher;
    this->swap(aux);
    return *this;
  }

  FLV& operator=(FLV&& outher)
  {
    auto aux = std::move(outher);
    this->swap(aux);
    return *this;
  }

  T& operator[](int i)
  {
    return contents[i];
  }

  void swap(FLV& other)
  {
    using std::swap;

    swap(contents, other.contents);
    swap(size_, other.size_);
  }

  T const& operator[](int i) const
  {
    return contents[i];
  }

private:
  T* contents;
  int size_;
};


}

#endif // !DATA_STRUCTUTURES_FIXED_LENGTH_VECTOR

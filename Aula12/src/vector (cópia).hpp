#ifndef DATA_STRUCTURES_VECTOR_HPP
#define DATA_STRUCTURES_VECTOR_HPP

#include <algorithm>
#include <bits/ranges_uninitialized.h>
#include <cstdint>
#include <memory>
#include <iostream>
#include <stdexcept>

//teste de cursor fsdfsnarce
//
/* 
 * contents -> [ 9 8 _ ]
 *                 * *
 *               0 1 2 3 4 5 6 7 8
 * contents -> [ 9 8 7 _ _ _ _ _ ]
 *                   *           * 
 *                   end         end_capacity 
 */                  
 


namespace data_structures {

template<typename T>
class Vector{
public:
  using size_type = std::ptrdiff_t;

private:
  struct VectorBase {
    VectorBase(size_type size):
      contents{static_cast<T*>(operator new(size * sizeof(T)))},
      end{contents + size},
      end_capacity{end} 
    {}
   
    VectorBase(size_type size, size_type capacity):
      contents{static_cast<T*>(operator new(capacity * sizeof(T)))},
      end{contents + size},
      end_capacity{contents + capacity} 
    {}

    ~VectorBase()
    {
      operator delete(contents);
    }

    VectorBase(VectorBase const&) = delete;
    VectorBase& operator=(VectorBase const&) = delete;

    VectorBase(VectorBase&& other)  noexcept:
      contents{other.contents},   
      end{other.end},
      end_capacity{other.end_capacity}

    {
      other.contents = other.end = nullptr;
    }

    VectorBase& operator=(VectorBase&& other) noexcept
    {
      this->swap(other);
      //std::cerr << "swap ok\n";
      return *this;

    }

    void swap(VectorBase& other)
    {
      using std::swap;
      swap(contents, other.contents);
      swap(end, other.end);
      swap(end_capacity, other.end_capacity);
    }
    T* contents;
    T* end;
    T* end_capacity;
  };
  
public:
  Vector(size_type n, T const& default_value = T{});
  ~Vector()
  {
    clear();
  }
  
  Vector(Vector const& other);
  
  Vector(Vector&& other) = default;

  Vector& operator=(Vector&& other)
  {
    auto aux = std::move(other);
    this->swap(aux);
  }

  size_type size() const noexcept
  {
    return base.end - base.contents;
  }

  size_type capacity() const noexcept
  {
    return base.end_capacity - base.contents;
  }

  void push_back(T elem);

  void reserve(size_type new_size);

  void shrink_to_fit();

  void clear()
  {
    for (auto p = base.contents; p != base.end; ++p) {
      p->~T();
    }
    base.end = base.contents;
  }

  void swap(Vector& other)
  {
    using std::swap;
    swap(base, other.base);
  }

  T& operator[](size_type i)
  {
    return base.contents[i];
  }

  T const& operator[](size_type i) const
  {
    return base.contents[i];
  }

  T& at(size_type i)
  {
    if (i <0 || i >= size()){
      throw std::out_of_range("Access out of bounds in Vector.");
    }
    bounds_check(i);
    return *this[i];
  }

  T const& at(size_type i) const
  {
    bounds_check(i);
    return *this[i];
  }

  T* begin()
  {
    return base.contents;
  }

  T* end()
  {
    return base.end;
  }

  T* const* begin() const
  {
    return base.contents;
  }

  T* const* end() const
  {
    return base.end;
  }

  T& back()
  {
    return *(base.end -1);
  }

  T const& back() const
  {
    return *(base.end -1);
  }

  T& front()
  {
    return *base.contents;
  }

  T const& front() const
  {
    return *base.contents;
  }

  T* data()
  {
    return base.contents;
  }

  T const* data() const
  {
    return base.contents;
  }


private:
  void bounds_check(size_type i)
  {

 if (i <0 || i >= size()){
      throw std::out_of_range("Access out of bounds in Vector.");
    }
  }
  VectorBase base;
};

template<typename T>
Vector<T>::Vector(size_type n, T const& default_value): 
  base{n}
{
  std::uninitialized_fill(base.contents, base.end, default_value);
}

template<typename T>
Vector<T>::Vector(Vector const& other):
  base{other.size()}
{
  std::uninitialized_copy(other.base.contents, other.base.end, base.contents);
}
  
template <typename T>
void Vector<T>::reserve(size_type new_capacity)
{
  // auto size = this->size();
  // 
  // auto new_contents = operator new(new_capacity * sizeof(T));

  // try {
  //   std::uninitialized_move(contents, end, new_contents);
  // } catch (...) {
  //   operator delete(new_contents);
  //   throw;
  // }

  // for (auto p = contents; p != end; ++p) {
  //   p->~T();
  // }
  // operator delete(contents);
  // contents = new_contents;
  // end = contents + size;
  // end_capacity = contents + new_capacity;
  //
  if (new_capacity <= capacity()) {
    return;
  }

  //Implementação não muito boa
  // auto new_vector = Vector{new_capacity};
  // std::copy(base.contents, base.end, new_vector.base.contents);
  // swap(*this, new_vector);

  auto new_base = VectorBase{size(), new_capacity};
  std::uninitialized_move(base.contents, base.end, new_base.contents);
  base = std::move(new_base);
}

template <typename T>
void Vector<T>::shrink_to_fit()
{
  auto size_ = size();

  if (size_ == capacity()) {
    return;
  }
  
  auto new_base = VectorBase{size_};
  std::uninitialized_move(base.contents, base.end, new_base.contents);
  base = std::move(new_base);
}

template<typename T>
void Vector<T>::push_back(T elem)
{
  //std::cout << size() << '\n';

  if (size() == capacity()) {
    //realloc ?
    reserve(2 * size());  
  }

  new(base.end) T{std::move(elem)};
  ++base.end;
}

}

#endif // !DATA_STRUCTURES_VECTO_HPP

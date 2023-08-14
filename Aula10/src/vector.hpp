#ifndef DATA_STRUCTURES_VECTOR_HPP
#define DATA_STRUCTURES_VECTOR_HPP

#include <cstddef>
#include <cstdint>
#include <iterator>
#include <memory>
#include <new>

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
class Vector {
public:
  using size_type = std::ptrdiff_t;

  Vector(size_type n, T const& default_value = T{});
  ~Vector();
  
  Vector(Vector const& other);
  
  Vector(Vector&& other):
    contents{other.contents},
    end{other.end},
    end_capacity{other.end_capacity}
  {
    other.contents = other.end = nullptr;
  }

  Vector& operator=(Vector&& other)
  {
    auto aux = std::move(other);
    this->swap(aux);
    
    return *this;
  }

  size_type size() const noexcept
  {
    return end - contents;
  }
  
  void push_back(T const& elem);

  void reserve(size_type new_size);

  void swap(Vector& other)
  {
    using std::swap;
    swap(contents, other.contents);
    swap(end, other.end);
    swap(end_capacity, other.end_capacity);
  }
  

private:
  T* contents;
  T* end;
  T* end_capacity;
};

// Operator new:
// 
// - (T*) new T{}; //aloca e inicializa um T
// - (T*) new T[size]; //aloca e inicializa "size" Ts (com o construtor padrão)
// - (void*) operator new(size * sizeof(T)); aloca memória de tamanho size * sizeof(T)
// - () new(T* t) T{...}; // inicializa memória previamente alocada  
//

template<typename T>
Vector<T>::Vector(size_type n, T const& default_value): 
  contents{static_cast<T*>(operator new(n * sizeof(T)))},
  end{contents + n},
  end_capacity{end}
{
  // T* p;

  // try {
  //   for (p = contents; p != end; ++p) {
  //     // initialize ??
  //   new (p) T{default_value};
  //   }
  // } catch (...) {
  //     for (T* q = contents; p != p; ++ q) {
  //     q->~T();
  //   }

  //   operator delete(contents);

  //   throw;
  // }
  //
  try {
    std::uninitialized_fill(contents, end, default_value);
  } catch (...) {
    operator delete(contents);
    throw;
  }
  
}

template <typename T>
Vector<T>::Vector(Vector const& other):
  contents{static_cast<T*>(operator new(other.size() * sizeof(T)))},
  end{contents + other.size()},
  end_capacity{end}
  {
    try {
         std::uninitialized_copy(other.contents, other.end, contents);
    }catch (...) {
        operator delete(contents);
        throw;
    }
  }

template<typename T>
Vector<T>::~Vector()
{
  for (auto p = contents; p != end; ++p) {
    p->~T();
  }
  operator delete(contents);
}

template <typename T>
void Vector<T>::reserve(size_type new_capacity)
{
  auto size = this->size();
  
  auto new_contents = operator new(new_capacity * sizeof(T));

  try {
    std::uninitialized_move(contents, end, new_contents);
  } catch (...) {
    operator delete(new_contents);
    throw;
  }

  for (auto p = contents; p != end; ++p) {
    p->~T();
  }
  operator delete(contents);
  contents = new_contents;
  end = contents + size;
  end_capacity = contents + new_capacity;
}

template<typename T>
void Vector<T>::push_back(T const& elem)
{
  if (end == end_capacity) {
    //realloc ?
    reserve(2 * size());  
  }

  new(end) T{elem};
  ++end;
}

}

#endif // !DATA_STRUCTURES_VECTO_HPP

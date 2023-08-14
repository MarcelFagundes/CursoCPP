#include <iostream>
#include <memory>
#include <vector>



class Serializable {
public:
  virtual ~Serializable() = default;
  virtual void serialize() const = 0;
};

class DisplayFile: public Serializable  {
public:
    DisplayFile(std::vector<std::unique_ptr<Serializable>> objects):
        objects{std::move(objects)}
    {
        std::cout << "DisplayFile()\n";
    }

    ~DisplayFile()
    {
        std::cout << "~DisplayFile()\n";
    }

    void serialize() const
    {
          std::cout << "DisplayFile {\n";
          std::cout << "    objects:  [\n";

          for (auto& object: objects) {
              object->serialize(); // ou (*object).serialize();
          }

          std::cout << "  ]\n";
          std::cout << "}\n";
    }

private:
  std::vector<std::unique_ptr<Serializable>> objects;
};


class Circle: public Serializable {
public:
  Circle(double radius): 
    radius{radius} 
  {
      std::cout << "Circle()\n";
  }

  Circle(Circle const& c): 
      radius{c.radius}
  {
    std::cout << "Circle(Circle const&)\n";
  } 

  ~Circle()
  {
    std::cout << "~Circle()\n";
  }

  void serialize() const
  {
    std::cout << "Circle {\n";
    std::cout << "   radius: " << radius << ",\n";
    std::cout << "}\n";
  }

private:
  double radius;
};


class Rectangle: public Serializable {
public:
  Rectangle(double side1, double side2): 
      side1{side1}, 
      side2{side2} 
  {
      std::cout << "Rectangle()\n";
  }

  Rectangle(Rectangle const& r): 
      side1{r.side1}, 
      side2{r.side2} 
  {
    std::cout << "Rectangle(Rectangle const&)\n";
  } 

  ~Rectangle()
  {
    std::cout << "~Rectangle()\n";
  }

  void serialize() const 
  {
    std::cout << "Rectangle {\n";
    std::cout << "   side1 " << side1 << ",\n";
    std::cout << "   side2 " << side2 << ",\n";
    std::cout << "}\n";
  }

private:
  double side1, side2;
};


void print_serializable(Serializable const& s) 
{ 
    s.serialize(); 
}


int main() 
{
  auto circle = Circle{5.0};
  auto rectangle = Rectangle{2.0, 3.0};

  auto objects = std::vector<std::unique_ptr<Serializable>>{};
  
  objects.push_back(std::make_unique<Circle>(circle));
  objects.push_back(std::make_unique<Rectangle>(rectangle));
  
  {   
    auto display_file = DisplayFile{std::move(objects)}; 

    print_serializable(display_file); 
  }
}

// objects.push_back(std::unique_ptr<Serializable>{new Circle{circle}});
  // objects.push_back(std::unique_ptr<Serializable>{new Rectangle{rectangle}}); 




  // Serializable &s1 = circle;
  // Serializable &s2 = rectangle;

  // s1.serialize();
  // s2.serialize();
  //
  // print_serializable(s1);
  // print_serializable(s2);
  //
  //print_serializable(circle);
  //print_serializable(rectangle);
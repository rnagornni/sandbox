#ifndef __GUITAR_H__
#define __GUITAR_H__
#include <string>
class Guitar
{
  private:
    std::string SerialNumber;
    double price;
    std::string builder;
    std::string model;
    std::string type;
    std::string backWood;
    std::string topWood;
  public:
    Guitar() = default;
    Guitar(std::string serial, double price, std::string builder, std::string model, std::string type, std::string backw, std::string topw)
    {
      SerialNumber = serial;
      this->price = price;
      this->builder = builder;
      this->model = model;
      this->type = type;
      backWood = backw;
      topWood = topw;
    }
    void setSerialNumber(std::string serial)
    {
      SerialNumber = serial;
    }
    std::string getSerialNumber() const
    {
      return SerialNumber;
    }
    void setPrice(double price)
    {
      this->price = price;
    }
    double getPrice() const
    {
       return price;
    }
    void setBuilder(std::string builder)
    {
      this->builder = builder;
    }
    std::string getBuilder() const
    {
       return builder;
    }
    void setModel(std::string model)
    {
      this->model = model;
    }
    std::string getModel() const
    {
       return model;
    }
    void setType(std::string type)
    {
      this->type = type;
    }
    std::string getType() const
    {
       return type;
    }
    void setBackWood(std::string wood)
    {
      backWood = wood;
    }
    std::string getBackWood() const
    {
       return backWood;
    }
    void setTopWood(std::string wood)
    {
      topWood = wood;
    }
    std::string getTopWood() const
    {
       return topWood;
    }
    bool operator == (const Guitar& guitar)
    {
      return guitar.getSerialNumber().compare(this->SerialNumber) == 0 
                 && guitar.getBuilder().compare(this->builder) == 0
                 && guitar.getModel().compare(this->model) == 0
                 && guitar.getType().compare(this->type) == 0
                 && guitar.getBackWood().compare(this->backWood) == 0
                 && guitar.getTopWood() == this->topWood;                   
    }
};
#endif //__GUITAR_H__

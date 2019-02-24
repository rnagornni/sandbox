#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "guitar.h"
#include <vector>

class Inventory
{
  private:
    std::vector<Guitar> m_guitars;
  public:
    void addGuitar(std::string serial, 
                   double price, 
                   std::string builder, 
                   std::string model, 
                   std::string type, 
                   std::string backw, 
                   std::string topw);
    Guitar getGuitar(std::string serial);
    Guitar ssearch(Guitar guitar);
};
#endif // __INVENTORY_H__

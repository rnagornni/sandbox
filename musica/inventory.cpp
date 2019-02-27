#include "inventory.h"

void Inventory::addGuitar(std::string serial, 
               double price, 
               std::string builder, 
               std::string model, 
               std::string type, 
               std::string backw, 
               std::string topw)
{
  m_guitars.push_back(Guitar(serial, price, builder, model, type, backw, topw));
}

Guitar Inventory::getGuitar(std::string serial)
{
  for(const auto &gt : m_guitars)
  {
    if(gt.getSerialNumber() == serial)
      return gt;
  }
  return Guitar();
}

Guitar Inventory::ssearch(Guitar guitar)
{
  for(const auto &g: m_guitars)
  {
    if(guitar == g)
     return g;
  }
  return Guitar();
}

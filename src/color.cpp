/**
 * Computer Graphics - Assignment 1
 * Copyright (C) 2019  Gabriel Moraes de Oliveira <biel94moraes@msn.com>
 */



#include "color.h"



std::ostream& operator<<(std::ostream& os, const Color& color)
{
  os << "RGBA";

  // Decimal format
  os << "(" << std::setw(3) << std::setfill('0') << std::dec << (uint16_t)color.getR();
  os << ", " << std::setw(3) << std::setfill('0') << std::dec << (uint16_t)color.getG();
  os << ", " << std::setw(3) << std::setfill('0') << std::dec << (uint16_t)color.getB();
  os << ", " << std::setw(3) << std::setfill('0') << std::dec << (uint16_t)color.getA();
  os << ")";

  // Hexadecimal format
#ifdef COLOR_STRING_HEXADECIMAL
  os << "(0x" << std::setw(2) << std::hex << std::uppercase << +color.getR();
  os << std::setw(2) << std::hex << std::uppercase << +color.getG();
  os << std::setw(2) << std::hex << std::uppercase << +color.getB();
  os << std::setw(2) << std::hex << std::uppercase << +color.getA();
  os << ")";
#endif

  return os;
}

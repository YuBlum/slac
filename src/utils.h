#ifndef SLAC_UTILS_H_
#define SLAC_UTILS_H_

#define SLAC_VANUM(...) (sizeof((slac_scalar []){ 0,##__VA_ARGS__ }) / sizeof(slac_scalar) - 1)

#endif/*SLAC_UTILS_H_*/

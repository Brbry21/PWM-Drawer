/*
 * Bit_Wise.h
 *
 * Created: 1/26/2024 11:46:07 PM
 *  Author: Lenovo
 */ 


#ifndef BIT_WISE_H_
#define BIT_WISE_H_


#define SET_BIT(REG,BIT)			REG|=(1<<BIT)
#define CLR_BIT(REG,BIT)			REG&=(~(1<<BIT))
#define TOGGLE_BIT(REG,BIT)			REG^=(1<<BIT)
#define READ_BIT(REG,BIT)			((REG>>BIT) & 0x01)


#endif /* BIT_WISE_H_ */
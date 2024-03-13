/* 
 * File:   xl5.h
 * Author: joe
 *
 * Created on March 10, 2024, 5:59 PM
 */

#ifndef XL5_H
#define	XL5_H

struct xl5_data
{
    uint8_t drive_dir;      // Value of drive direction (0 or 1)
    uint8_t drive_dir_flag; // Whether drive direction has been sent/received
};

void init_XL5();
void throttle_test();

#endif	/* XL5_H */


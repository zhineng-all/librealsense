// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2020 Intel Corporation. All Rights Reserved.

#include "../algo-common.h"
#include "algo/thermal-loop/l500-thermal-loop.h"

namespace thermal = librealsense::algo::thermal_loop::l500;

thermal::thermal_calibration_table create_synthetic_table( const int table_size = 29 )
{
    thermal::thermal_calibration_table res;
    res._header.min_temp = 0;
    res._header.max_temp = 75;
    res._header.reference_temp = 100;
    res._header.valid = 1;
    res._resolution = table_size;
    res.vals.resize( table_size );

    // [0   - 2.5]  --> 0.5 
    // (2.5 - 5]    --> 1 
    // (5   - 7.5]  --> 1.5 
    // (7.5 - 10]   --> 2 
    // ...
    // (72.5 - 75]  --> 15
    for( auto i = 0; i < table_size; i++ )
    {
        res.vals[i].scale = ( i + 1 ) * 0.5;
        res.vals[i].sheer = 0;
        res.vals[i].tx = 0;
        res.vals[i].ty = 0;
    }
    return res;
}

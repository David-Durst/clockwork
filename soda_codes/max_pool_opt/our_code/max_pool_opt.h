#pragma once


#include "hw_classes.h"

void max_pool_opt(HWStream<hw_uint<512> >& /* get_args num ports = 16 */in_oc, HWStream<hw_uint<256> >& /* get_args num ports = 8 */max_pool);
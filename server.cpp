//
// Created by ashish on 1/17/22.
//

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <functional>
#include <utility>
#include "Test.h"
int main ()
{
    using namespace boost::interprocess;

    // remove earlier existing SHM
    shared_memory_object::remove("SharedMemoryName");

    // create new
    shared_memory_object segment(create_only,"SharedMemoryName",read_write);
    std::cout<<sizeof(volModelCurve)<<","<<sizeof(volModelCurveStrike)<<std::endl;
    segment.truncate(sizeof(volModelCurve));

    mapped_region region(segment, read_write);
    std::memset(region.get_address(), 0, sizeof(volModelCurve));

    //Test* data = reinterpret_cast<Test*>(region.get_address());
    //fill(data);
    return 0;
}

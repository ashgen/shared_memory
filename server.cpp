
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
#include <thread>
#include "Test.h"
int main ()
{
    using namespace boost::interprocess;

    // remove earlier existing SHM
    shared_memory_object::remove("volModelSharedMem");

    // create new
    shared_memory_object segment(create_only,"volModelSharedMem",read_write);
    std::cout << sizeof(volModelCurve) << "," << sizeof(volModelCurveStrike) << std::endl;
    segment.truncate(sizeof(volModelCurve));

    mapped_region region(segment, read_write);
    std::memset(region.get_address(), 0, sizeof(volModelCurve));

    volModelCurve* testObj = reinterpret_cast<volModelCurve*>(region.get_address());
    int i = 0;
    while(1) {
        testObj->rho = 50 - i;
        testObj->arrayOfVolStrikes[5].valid = true;
        testObj->arrayOfVolStrikes[5].iv = i * 2;
        i++;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    std::cout << "Done dumping " << std::endl;
    //fill(data);
    return 0;
}

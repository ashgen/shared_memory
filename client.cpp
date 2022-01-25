//
// Created by ashish on 1/17/22.
//

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <functional>
#include <utility>
#include <iostream>
#include <thread>
#include "Test.h"
int main ()
{
    using namespace boost::interprocess;
    shared_memory_object segment(open_or_create, "volModelSharedMem",read_only);
    mapped_region region(segment, read_only);
    volModelCurve* data = reinterpret_cast<volModelCurve*>(region.get_address());

  while(1){
        try
        {
            std::cout << data->atmiv <<"," << data->rho<<","<<data->eta<<std::endl;
            for(auto x:data->arrayOfVolStrikes){
              if(x.valid)
              std::cout<<x.token << "," << x.iv <<"," << x.modelIV<<std::endl;
            }
        }catch(std::exception &e)
        {
            std::cout<<" error  " << e.what() <<std::endl;
            shared_memory_object::remove("volModelSharedMem");
        }
       std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
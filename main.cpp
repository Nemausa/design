#include <iostream>
#include "creational/factory.hpp"
#include "creational/singleton.hpp"
#include "creational/builder.hpp"
#include "behavioral/proxy.hpp"
#include "behavioral/proxy2.hpp"
#include "behavioral/state.hpp"
#include "behavioral/mediator.hpp"

int main()
{
    std::cout << "Nemausa" << std::endl;
    //creational::factory::main();
    //creational::singleton::main();
    //creational::builder::main();
    //behavioral::proxy::main();
    //behavioral::state::main();
    behavioral::mediator::main();
    return 0;
}
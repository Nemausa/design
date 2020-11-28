#include <iostream>
#include "creational/factory.hpp"
#include "creational/singleton.hpp"
#include "creational/builder.hpp"
#include "creational/prototype.hpp"

#include "behavioral/observer.hpp"
#include "behavioral/state.hpp"
#include "behavioral/mediator.hpp"

#include "structural/composite.hpp"
#include "structural/proxy.hpp"
#include "structural/proxy2.hpp"

#include "other/switch.hpp"

int main()
{
    std::cout << "Nemausa" << std::endl;
    //other::sw::main();
    //creational::factory::main();
    //creational::singleton::main();
    //creational::builder::main();
    //creational::singleton::main();
    creational::prototype::main();
    //behavioral::proxy::main();
    //behavioral::state::main();
    //behavioral::mediator::main();
    //behavioral::observer::client_code();
    //structural::composite::main();

    return 0;
}
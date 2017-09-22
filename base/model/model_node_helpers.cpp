#include "model_node_helpers.h"
#include <iostream>
#include "model_node.h"
namespace gle{
    int i=0;

    void printSpaces(){
        for(int k=0;k<i;k++)std::cout<<"  ";
    }

    void debugModelNodes(const ModelNode & node) {
        i++;
        printSpaces();
        std::cout<<node.getChildrenCount()<<":";
        for(unsigned int i=0; i<node.getVboIndexArraySize(); i++) {
            std::cout<<node.getVboIndex(i)<<",";
        }
        std::cout<<"\n";


        for(unsigned int i=0; i<node.getChildrenCount(); i++) {
            printSpaces();
            std::cout<<i<<"\n";
            debugModelNodes(*node.getChild(i).get());
        }
        i--;
    }

}

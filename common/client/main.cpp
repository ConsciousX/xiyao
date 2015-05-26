#include "Client.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    xiyao::common::Client client;
    client.connect(argv[1], atoi(argv[2]));
    client.poll();
}

#include "../Classes/AppDelegate.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>

USING_NS_CC;

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    // create the application instance
    CAppDelegate app;
    return Application::getInstance()->run();
}

#include "Controller.h"
#include "Model_base.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    Controller A;
    Model_base B;
    Model_base::Load_deal_new();
    A.Menu();
    Model_base::Write_deals();
   
}
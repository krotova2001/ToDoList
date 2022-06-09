#include "Controller.h"
#include "Model_base.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    Controller A;
    Model_base B;
    B.Add();
    B.Add();
    B.Show_all();
    B.Write_deals();
   
}
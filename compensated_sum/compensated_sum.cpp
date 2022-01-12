#include <iostream>
#include <cmath>
#include <iomanip>
int main(int argc, char const *argv[])
{
    const double big_num = 4.0;
    const double small_num = 0.000009123123;
    double normal_sum = big_num;
    double compensated_sum = big_num;
    size_t loop = 100000;
    for (int i = 0; i < loop; i++)
    {
        // normal
        normal_sum += small_num;
    }
    double tmp = 0.0, y = 0.0, e = 0.0;
    for (int i = 0; i < loop; i++)
    {
        // compensate summation
        tmp = compensated_sum;
        y = small_num + e;
        compensated_sum = y + tmp;
        e = (tmp - compensated_sum) + y; //(e < 0)
    }
    const double abs_s = 4.9123123;
    std::cout << "Accurate value is 4.9123123 \n";
    std::cout << "normal      " << std::setprecision(20) << normal_sum << " error " << std::fabs(abs_s - normal_sum) << std::endl;
    std::cout << "compensate  " << std::setprecision(20) << compensated_sum << " error " << std::fabs(abs_s - compensated_sum) << std::endl;
    std::cout << "multiple    " << std::setprecision(20) << static_cast<double>(loop) * small_num << std::endl;
    std::cout << "compensate summation's error is lowest !!!\n"; 
    return 0;
}

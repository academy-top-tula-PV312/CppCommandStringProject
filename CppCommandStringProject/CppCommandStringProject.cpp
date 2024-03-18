#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <typeinfo>

int Sum(int a, int b)
{
    return a + b;
}

int Mult(int a, int b)
{
    return a * b;
}

int Calc(int a, int b, int(*oper)(int, int))
{
    return oper(a, b);
}

int main(int argc, char* argv[])
{
    std::vector<int> v;
    std::map<std::string, std::vector<double>> m1;

    auto it = m1.begin();
    std::cout << typeid(it).name() << "\n";

    std::cout << Calc(10, 20, Sum) << "\n";

    int c = 50;
    double x = 56;
    auto del = [&](auto a, auto b)
        {
            c = 500 + x;
            return a - b + c;
        };

    std::cout << del(100, 200) << "\n";

    std::cout << Calc(10, 20, [](auto a, auto b)
        {
            return a - b;
        }) << "\n";


    /*for (int i{}; i < argc; i++)
        std::cout << argv[i] << "\n";*/
    FILE* file;

    if (strcmp(argv[1], "-w") == 0)
    {
        file = fopen(argv[2], "w");
        fputs("Hello world", file);

        std::cout << "Data write to file\n";

        fclose(file);
    }
    else if (strcmp(argv[1], "-r") == 0)
    {
        file = fopen(argv[2], "r");
        char* buffer = new char[1024];
        fgets(buffer, 1024, file);

        std::cout << buffer << "\n";

        fclose(file);
    }
    else
        std::cout << "incorrect command line\n";
}

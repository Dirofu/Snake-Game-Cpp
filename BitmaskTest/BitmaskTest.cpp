#include <iostream>
#include <bitset>

void ShowBinary(int mask)
{
    std::bitset<4> bitset = mask;
    std::cout << "Binary : " << bitset.to_string<char, std::char_traits<char>, std::allocator<char> >() << std::endl;
}

int main()
{
    short mask = 0;

    while (true)
    {
        int i = 0;
        ShowBinary(mask);
        std::cin >> i;
        
        if (i == 0)
            break;

        if (mask & (1 << i - 1))
        {
            std::cout << "Mask was enabled" << std::endl;
            mask &= ~(1 << i - 1);
        } 
        else
        {
            std::cout << "Mask was disabled" << std::endl;
            mask |= (1 << i - 1);
        }

        ShowBinary(mask);
        std::cout << mask << std::endl;
        system("pause");
        std::cout << std::endl;
    }
}
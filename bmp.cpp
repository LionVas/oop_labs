#include <fstream>
#include <cstdint>
int main()
{
    std::ofstream os("image.bmp", std::ios_base::binary
                                | std::ios_base::out);

    //std::uint8_t, std::uint16_t, std::uint32_t

    std::uint16_t n = 0x4D42;
    std::uint32_t k = 0x00000046;
    std::uint8_t j =0xFF;
    //FILE*
    os.write(reinterpret_cast<char*>(&n), sizeof(std::uint16_t));
    os.write(reinterpret_cast<char*>(&k), sizeof(std::uint32_t));
    n = 0x0000;
    os.write(reinterpret_cast<char*>(&n), sizeof(std::uint16_t));
    os.write(reinterpret_cast<char*>(&n), sizeof(std::uint16_t));
    k = 0x00000036;
    os.write(reinterpret_cast<char*>(&k), sizeof(std::uint32_t));
    k=0x00000028;
    os.write(reinterpret_cast<char*>(&k), sizeof(std::uint32_t));
    k = 0x00000002;
    os.write(reinterpret_cast<char*>(&k), sizeof(std::uint32_t));
    os.write(reinterpret_cast<char*>(&k), sizeof(std::uint32_t));
    n=0x0001;
    os.write(reinterpret_cast<char*>(&n), sizeof(std::uint16_t));
    n=0x0018;
    os.write(reinterpret_cast<char*>(&n), sizeof(std::uint16_t));
    k = 0x00000000;
    os.write(reinterpret_cast<char*>(&k), sizeof(std::uint32_t));
    k = 0x00000010;
    os.write(reinterpret_cast<char*>(&k), sizeof(std::uint32_t));
    k = 0x00000B13;
    os.write(reinterpret_cast<char*>(&k), sizeof(std::uint32_t));
    os.write(reinterpret_cast<char*>(&k), sizeof(std::uint32_t));
    k = 0x00000000;
    os.write(reinterpret_cast<char*>(&k), sizeof(std::uint32_t));
    os.write(reinterpret_cast<char*>(&k), sizeof(std::uint32_t));
    n = 0x0000;
    os.write(reinterpret_cast<char*>(&n), sizeof(std::uint16_t));
    os.write(reinterpret_cast<char*>(&j), sizeof(std::uint8_t));
    n = 0xFFFF;
    os.write(reinterpret_cast<char*>(&n), sizeof(std::uint16_t));
    os.write(reinterpret_cast<char*>(&j), sizeof(std::uint8_t));
    n = 0x0000;
    os.write(reinterpret_cast<char*>(&n), sizeof(std::uint16_t));
    n = 0x00FF;
    j = 0x00;
    os.write(reinterpret_cast<char*>(&n), sizeof(std::uint16_t));
    os.write(reinterpret_cast<char*>(&j), sizeof(std::uint8_t));
    n = 0xFF00;
    os.write(reinterpret_cast<char*>(&n), sizeof(std::uint16_t));
    os.write(reinterpret_cast<char*>(&j), sizeof(std::uint8_t));
    n = 0x0000;
    os.write(reinterpret_cast<char*>(&n), sizeof(std::uint16_t));
    os.close();
    return 0;
}

//#include <iostream>
//#include <memory>
//#include "../Interface/CParser.h"
//
//static const auto failed_string {"Failed"};
//static const auto pass_string {"Pass"};
//
//void Test1()
//{
//    std::vector<unsigned char> data {0xFF,0x98,
//                                     0xFF,0x5A,0,0x22,0x7b,
////                                      0x40,0x40,0,0x1D,0x4E,0x00,
////                                     0x00,0x04,0x00,0x01,
////                                      0x00,0x04,0x00,0x02,
////                                      0x00,0x05,0x00,0x03,0x11,
////                                      0x00,0x05,0x00,0x04,0x34,
////                                      0x00,0x05,0x00,0x05,0x56,
////
//                                  0xFF,0x34,0x76,0xFF,0x5A,0x66,
//                                  0xFF,0x5A,0,0x22,0x7b,
//                                  0x40,0x40,0,0x1D,0x4E,0x00,
//                                  0x00,0x04,0x00,0x01,
//                                  0x00,0x04,0x00,0x02,
//                                  0x00,0x05,0x00,0x03,0x11,
//                                     0x00,0x05,0x00,0x04,0x34,
//                                  0x00,0x05,0x00,0x05,0x56,0x5e};
//
////    std::vector<unsigned char> data {0xFF, 0x5A};
//    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
//    auto message = parser->Parse(data);
//    std::cout << "Test case 1 " << (message ? failed_string : pass_string) << "!" << std::endl;
//}
//
//int main()
//{
//    Test1();
//    return 0;
//}


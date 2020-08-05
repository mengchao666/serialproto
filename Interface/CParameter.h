//
// Created by zhaoshunxian on 2020/7/29.
//

#ifndef SERIALPROTO__CPARAMETER_H_
#define SERIALPROTO__CPARAMETER_H_

#include "../optional.hpp"
#include <vector>
#include <string>
#include "../Sample/types.h"

using namespace std;

class CParameter
{
public:
    using type_enum = enum _type_enum:unsigned char{};
    using type_string = std::string;
    using type_blob = std::vector<unsigned char>;
    using type_none = struct _type_none{};
    using type_group = std::vector<CParameter>;
    unsigned short GetID();
    std::experimental::optional<char> GetInt8();
    std::experimental::optional<unsigned char> GetUint8();
    std::experimental::optional<short> GetInt16();
    std::experimental::optional<unsigned short> GetUint16();
    std::experimental::optional<int> GetInt32();
    std::experimental::optional<unsigned int> GetUint32();
    std::experimental::optional<long long int> GetInt64();
    std::experimental::optional<unsigned long long int> GetUint64();
    std::experimental::optional<float> GetFloat();
    std::experimental::optional<double> GetDouble();
    std::experimental::optional<type_enum> GetEnum();
    std::experimental::optional<bool> GetBoolean();
    std::experimental::optional<type_string> GetString();
    std::experimental::optional<type_blob> GetBlob();
    std::experimental::optional<type_none> GetNone();
    CParameter::type_group GetGroup();

    unsigned short parameter_ID;
    vector<uint8> parameter_data;
private:

};

#endif //SERIALPROTO__CPARAMETER_H_

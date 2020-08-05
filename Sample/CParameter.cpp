//
// Created by zhaoshunxian on 2020/7/29.
//

#include <cstring>
#include "../Interface/CParameter.h"
#include <iostream>


unsigned short CParameter::GetID()
{
    return parameter_ID;
}

std::experimental::optional<unsigned char> CParameter::GetUint8()
{
    if (parameter_data.size() == 1)
    {
        return parameter_data[0];
    }
    return {};
}

std::experimental::optional<char> CParameter::GetInt8()
{
    if (parameter_data.size() == 1)
    {
        return parameter_data[0];
    }
    return {};
}


std::experimental::optional<unsigned short> CParameter::GetUint16()
{
    if (parameter_data.size() == 2)
    {
        unsigned short tmp= parameter_data[0] << 8 + parameter_data[1];
        return tmp;
    }
    return {};
}

std::experimental::optional<short> CParameter::GetInt16()
{
    if (parameter_data.size() == 2)
    {
        short tmp= parameter_data[0] << 8 + parameter_data[1];
        return tmp;
    }
    return {};
}


std::experimental::optional<unsigned int> CParameter::GetUint32()
{
    union CharToInt
    {
        unsigned int d;
        char c[4];
    };

    CharToInt cti;//解析int用

    if (parameter_data.size() == 4)
    {
        for(int i=0;i<4;i++)
        {
            cti.c[i] = parameter_data[i];
        }
        return cti.d;
    }
    return {};
}

std::experimental::optional<int> CParameter::GetInt32()
{
    union CharToInt
    {
        int d;
        char c[4];
    };

    CharToInt cti;//解析int用

    if (parameter_data.size() == 4)
    {
        for(int i=0;i<4;i++)
        {
            cti.c[i] = parameter_data[i];
        }
        return cti.d;
    }
    return {};
}


std::experimental::optional<long long int> CParameter::GetInt64()
{
    union CharToInt
    {
        long long int d;
        char c[8];
    };

    CharToInt cti;//解析int用

    if (parameter_data.size() == 8)
    {
        for(int i=0;i<8;i++)
        {
            cti.c[i] = parameter_data[i];
        }
        return cti.d;
    }
    return {};
}

std::experimental::optional<unsigned long long int> CParameter::GetUint64()
{
    union CharToInt
    {
        unsigned long long int d;
        char c[8];
    };

    CharToInt cti;//解析int用

    if (parameter_data.size() == 8)
    {
        for(int i=0;i<8;i++)
        {
            cti.c[i] = parameter_data[i];
        }
        return cti.d;
    }
    return {};
}


std::experimental::optional<float> CParameter::GetFloat()
{
    union CharToFloat
    {
        float d;
        char c[4];
    };
    CharToFloat ctf;//解析float用
    if (parameter_data.size() == 4)
    {
        for(int i=0;i<4;i++)
        {
            ctf.c[i] = parameter_data[i];
        }
        return ctf.d;
    }
    return {};

}

std::experimental::optional<double> CParameter::GetDouble()
{
    union CharToDouble
    {
        double d;
        char c[8];
    };

    CharToDouble ctd;//解析double用
    if (parameter_data.size() == 8)
    {
        for(int i=0;i<8;i++)
        {
            ctd.c[i] = parameter_data[i];
        }
        return ctd.d;
    }
    return {};

}

std::experimental::optional<CParameter::type_enum> CParameter::GetEnum()
{
//    if (parameter_data.size() > 0)
//    {
        std::cout << "parameter_data[0] = " << (int)parameter_data[0] << endl;
        return std::experimental::optional<CParameter::type_enum>((CParameter::type_enum)parameter_data[0]);
//    }
//    return {};
}

std::experimental::optional<bool> CParameter::GetBoolean()
{
    if (parameter_data.size() == 1)
    {
        return parameter_data[0];
    }
    return {};
}

std::experimental::optional<CParameter::type_string> CParameter::GetString()
{
    for(int i=0;i<parameter_data.size();i++)
    {
        if(parameter_data[i] == 0)
        {
            char* p = new char[i];
            for(int j=0;j<=i;j++)
            {
                p[j] = parameter_data[j];
            }
            string str(p);
            return str;
        }
    }
    return {};
}

std::experimental::optional<CParameter::type_blob> CParameter::GetBlob()
{
    if(parameter_data.size() != 0)
    {
        return parameter_data;
    }
    return {};
}

std::experimental::optional<CParameter::type_none> CParameter::GetNone()
{
    return std::experimental::optional<CParameter::type_none>();
}

CParameter::type_group CParameter::GetGroup()
{
    if(parameter_data.size() == 0)
    {
        return {};
    }

    int tmp  = 0 ;

    vector<CParameter> res;
    while(tmp < parameter_data.size()-1)
    {
        CParameter CPa;

        int parameter_length = 4;
        char c1 = parameter_data[0 + tmp];
        char c2 = parameter_data[1 + tmp];
        unsigned short parameter_ID = c1*256 +c2 ;//3�ǲ���ID��Ӧ��λ
        CPa.parameter_ID = parameter_ID;


        for(int i=0;i<parameter_length;i++)
        {
            CPa.parameter_data.push_back(parameter_data[tmp + i]);
        }

        res.push_back(CPa);
        tmp = tmp + parameter_length;
    }
    return res;
}
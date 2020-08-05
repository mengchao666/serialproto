#include "requestknob.h"

RequestKnob::RequestKnob()
    :MessageBase(messageID,paranum)
{
}

int RequestKnob::displayParaID(int paraID , int parameter_length , int &flag)
{
    if(paraID == 0)
    {
        std::cout << "参数名称是Button:主按钮" << std::endl;
        flag++;
        return 0;
    }
    else if(paraID == 1)
    {
        std::cout << "参数名称是ACHome:返回到主页面" << std::endl;
        flag++;
        return 0;
    }
    else if(paraID == 2)
    {
        std::cout << "参数名称是ACBack:返回上一级菜单" << std::endl;
        flag++;
        return 0;
    }
    else if(paraID == 3 && parameter_length-kParameterHeaderLength == kSizeofChar)
    {
        std::cout << "参数名称是X:左右倾斜操作， X 轴坐标位置的绝对值" << std::endl;
        flag++;
        return 0;
    }
    else if(paraID == 4 && parameter_length-kParameterHeaderLength == kSizeofChar)
    {
        std::cout << "参数名称是Y:前后倾斜操作， Y 轴坐标位置的绝对值" << std::endl;
        flag++;
        return 0;
    }
    else if(paraID == 5 && parameter_length-kParameterHeaderLength == kSizeofChar)
    {
        std::cout << "参数名称是Wheel:旋转操作， 滚动条位置的相对值" << std::endl;
        flag++;
        return 0;
    }
    else
    {
        std::cout << "无当前参数名称，或参数错误,已忽略" << std::endl;
        return -1;
    }
}



void RequestKnob::displayData(int paraID,char paradata)
{
    if(paraID == 3)
    {
        std::cout << "左右倾斜操作， X 轴坐标位置的绝对值为:" << "0x" << (int)paradata << std::endl;
    }

    if(paraID == 4)
    {
        std::cout << "前后倾斜操作， Y 轴坐标位置的绝对值为:" << "0x" <<(int)paradata << std::endl;
    }

    if(paraID == 5)
    {
        std::cout << "旋转操作， 滚动条位置的相对值为:" << "0x" << (int)paradata << std::endl;
    }

}

vector<CParameter> RequestKnob::ParameterAnalysis(vector<uint8> receive_package,vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message)
{
    int flag = 0;
    union CharToDouble
    {
        double d;
        char c[8];
    };

    CharToDouble ctd;//����double��

    union CharToInt
    {
        int d;
        char c[4];
    };

    CharToInt cti;//����int��

    int tmp  = 0 ;
    receive_package.erase(receive_package.begin(),receive_package.begin()+kPackageHeaderLength);

    while(tmp < receive_package.size()-1)
    {
        CParameter CPa;
        char parameter_length =  receive_package[1 + tmp];//1�ǲ������ȶ�Ӧ��λ

        char c1 = receive_package[2 + tmp];
        char c2 = receive_package[3 + tmp];
        unsigned short parameter_ID = c1*256 +c2 ;//3�ǲ���ID��Ӧ��λ
        CPa.parameter_ID = parameter_ID;

        displayParaID(parameter_ID ,parameter_length ,flag);

        for(int i=0;i<parameter_length-kParameterHeaderLength;i++)
        {
            CPa.parameter_data.push_back(receive_package[kParameterHeaderLength + tmp + i]);
        }


//        if(parameter_length-kParameterHeaderLength == kSizeofChar)
//        {
//            unsigned char parameter_data = 0;
//            for(int j=0;j<parameter_length-kParameterHeaderLength;++j)
//            {
//                parameter_data =  receive_package[kParameterHeaderLength + tmp + j];
//                CPa.parameter_data.push_back(parameter_data);
//            }
//        }
//
//        if(parameter_length-kParameterHeaderLength == kSizeofInt)
//        {
//            int parameter_data = 0;
//            for(int j=0;j<parameter_length-kParameterHeaderLength;++j)
//            {
//                cti.c[j] = receive_package[kParameterHeaderLength + tmp + j];
//                CPa.parameter_data.push_back(cti.c[j]);
//            }
//        }
//
//        if(parameter_length-kParameterHeaderLength == kSizeofDouble)
//        {
//            double parameter_data = 0;
//            for(int j=0;j<parameter_length-kParameterHeaderLength;++j)
//            {
//                ctd.c[j] = receive_package[kParameterHeaderLength + tmp + j];
//                CPa.parameter_data.push_back(ctd.c[j]);
//            }
//        }
        parameter.push_back(CPa);
        tmp = tmp + parameter_length;
    }
    return  parameter;
}


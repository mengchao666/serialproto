#include "setwindowcaption.h"

SetWindowCaption::SetWindowCaption()
        :MessageBase(messageID,paranum)
{
}

int SetWindowCaption::displayParaID(int paraID , int parameter_length , int &flag)
{
    if(paraID == 0 )
    {
        std::cout << "参数名称是" << std::endl;
        flag++;
        return 0;
    }

    else
    {
        std::cout << "无当前参数名称，或参数错误,已忽略" << std::endl;
        return -1;
    }
}

void SetWindowCaption::displayData(int paraID,char paradata)
{
    if(paraID == 0)
    {
        std::cout << "淡入操作完成的时间，单位为秒值为:" << "0x" << (int)paradata << std::endl;
    }

    if(paraID == 1)
    {
        std::cout << "淡入操作的音量，取值为 0-1 之间值为:" << "0x" <<(int)paradata << std::endl;
    }

}

vector<CParameter> SetWindowCaption::ParameterAnalysis(vector<uint8> receive_package,vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message)
{
    int flag = 0;

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

        parameter.push_back(CPa);
        tmp = tmp + parameter_length;
    }
    if(flag < 1)
    {
        cout << "que shao bi yao can shu" << endl;
        return {};
    }

    return  parameter;
}




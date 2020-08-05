#include "include.h"
#include "requestknob.h"
#include "../Interface/CParameter.h"
#include "../Interface/CMessage.h"
#include "connectstatechanged.h"
#include "InitializeStart.h"
#include "initializerespond.h"
#include "initializefinish.h"
#include "streamsstatechanged.h"
#include "duckaudio.h"
#include "requestbuttonkey.h"
#include "requestphonekey.h"
#include "setbrakesignal.h"
#include "setrighthand.h"
#include "showwindow.h"
#include "unduckaudio.h"
#include "touchpaddatastop.h"
#include "touchpaddatastart.h"
#include "touchpaddatainit.h"
#include "touchpaddata.h"
#include "setwindowcaption.h"



using namespace std;

uint8 my_checksum_calculation(vector<uint8> vc)
{
    short i;
    char sum = 0;
    for (i = 5; i < vc.size()-1; i++)
    {
        sum += vc[i];
    }
    return (uint8)(0x100 - sum); //取二进制补码
}

MessageBase* CreateMessageIDptr(short mesID)
{
    if(mesID == kConnectStateChangedMessageID)
    {
        std::cout << "您的消息会话为ConnectStateChanged" << std::endl;
        ConnectStateChanged* pMsg;
        pMsg = new ConnectStateChanged();
        return pMsg;
    }

    else if(mesID == kStreamsStateChangedMessageID)
    {
        std::cout << "您的消息会话为StreamsStateChanged" << std::endl;
        StreamsStateChanged* pMsg;
        pMsg = new StreamsStateChanged();
        return pMsg;
    }

    else if(mesID == kShowWindowMessageID)
    {
        std::cout << "您的消息会话为ShowWindow" << std::endl;
        ShowWindow* pMsg;
        pMsg = new ShowWindow();
        return pMsg;
    }

    else if(mesID == kSetWindowCaptionMessageID)
    {
        std::cout << "您的消息会话为SetWindowCaption" << std::endl;
        SetWindowCaption* pMsg;
        pMsg = new SetWindowCaption();
        return pMsg;
    }

    else if(mesID == kDuckAudioMessageID)
    {
        std::cout << "您的消息会话为DuckAudio" << std::endl;
        DuckAudio* pMsg;
        pMsg = new DuckAudio();
        return pMsg;
    }

    else if(mesID == kUnduckAudioMessageID)
    {
        std::cout << "您的消息会话为UnduckAudio" << std::endl;
        UnduckAudio* pMsg;
        pMsg = new UnduckAudio();
        return pMsg;
    }

    else if(mesID == kSetBrakeSignalMessageID)
    {
        std::cout << "您的消息会话为SetBrakeSignal" << std::endl;
        SetBrakeSignal* pMsg;
        pMsg = new SetBrakeSignal();
        return pMsg;
    }

    else if(mesID == kRequestPhoneKeyMessageID)
    {
        std::cout << "您的消息会话为RequestPhoneKey" << std::endl;
        RequestPhoneKey* pMsg;
        pMsg = new RequestPhoneKey();
        return pMsg;
    }

    else if(mesID == kRequestButtonKeyMessageID)
    {
        std::cout << "您的消息会话为RequestButtonKey" << std::endl;
        RequestButtonKey* pMsg;
        pMsg = new RequestButtonKey();
        return pMsg;
    }


    else if(mesID == kSetRightHandMessageID)
    {
        std::cout << "您的消息会话为SetRightHand" << std::endl;
        SetRightHand* pMsg;
        pMsg = new SetRightHand();
        return pMsg;
    }

    else if(mesID == kTouchpadDataInitMessageID)
    {
        std::cout << "您的消息会话为TouchpadDataInit" << std::endl;
        TouchpadDataInit* pMsg;
        pMsg = new TouchpadDataInit();
        return pMsg;
    }

    else if(mesID == kRequestKnobMessageID)
    {
        std::cout << "您的消息会话为requestknob" << std::endl;
        RequestKnob* pMsg;
        pMsg = new RequestKnob();
        return pMsg;
    }

    else if(mesID == kTouchpadDataStartMessageID)
    {
        std::cout << "您的消息会话为TouchpadDataStart" << std::endl;
        TouchpadDataStart* pMsg;
        pMsg = new TouchpadDataStart();
        return pMsg;
    }

    else if(mesID == kTouchpadDataMessageID)
    {
        std::cout << "您的消息会话为TouchpadData" << std::endl;
        TouchpadData* pMsg;
        pMsg = new TouchpadData();
        return pMsg;
    }

    else if(mesID == kTouchpadDataStopMessageID)
    {
        std::cout << "您的消息会话为TouchpadDataStop" << std::endl;
        TouchpadDataStop* pMsg;
        pMsg = new TouchpadDataStop();
        return pMsg;
    }

    else if(mesID == kInitializeStartMessageID)
    {
        std::cout << "您的消息会话为InitializeStart" << std::endl;
        InitializeStart* pMsg;
        pMsg = new InitializeStart();
        return pMsg;
    }


    else if(mesID == kInitializeRespondMessageID)
    {
        std::cout << "您的消息会话为InitializeRespond" << std::endl;
        InitializeRespond* pMsg;
        pMsg = new InitializeRespond();
        return pMsg;
    }

    else if(mesID == kInitializeFinishMessageID)
    {
        std::cout << "您的消息会话为InitializeFinish" << std::endl;
        InitializeFinish * pMsg;
        pMsg = new InitializeFinish();
        return pMsg;
    }

    else
    {
        std::cout << "无当前会话" << std::endl;
        return nullptr;
    }
}



int MakeData(int &position ,uint16 &message_ID,vector<uint8> receive_package,
             vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message)//链路包起始位置确定
{
    while(1)
    {
        if( position < receive_package.size()-2  && receive_package[position] == kPackageHeaderMSB &&
                receive_package[position+1] == kPackageHeaderLSB)
        {
            break;
        }

        position++;

        if(position == receive_package.size()-1)
        {
            cout << "链路包起始头错误" << endl;
            return -1;
        }
    }

    if(receive_package.size() < kPackageHeaderLength)
    {
        cout << "链路包的长度过小，不符合" << endl;
        return -1;
    }


    PackageHeader package_header = {receive_package[position + 0],receive_package[position + 1],
                                    receive_package[position + 2],
                                    receive_package[position + 3],receive_package[position + 4]};

    MessageHeader message_header = {receive_package[position + 5],receive_package[position + 6],
                                    receive_package[position + 7],
                                    receive_package[position + 8],receive_package[position + 9],
                                    receive_package[position + 10]};



    receive_package.erase(receive_package.begin(),receive_package.begin()+position);//去掉头部多余数据

    unsigned short package_length;
    package_length = package_header.package_length_MSB * 256 + package_header.package_length_LSB;
    cout << "链路包长度为:" << "0x" << hex <<package_length << endl;

    if(package_length > receive_package.size())
    {
        cout << "长度不对，比当前传入的数据还长" << endl;
        return -1;
    }

    if(package_header.package_header_MSB != kPackageHeaderMSB &&
            package_header.package_header_LSB != kPackageHeaderLSB)
    {
        cout << "链路包起始头不正确" << endl;
        return -1;
    }
    uint8 header_sum = package_header.package_header_MSB
            +package_header.package_header_LSB
            +package_header.package_length_MSB
            +package_header.package_length_LSB;

    if(package_header.package_header_sum  != header_sum)
    {
        cout << "链路包头部校验和错误" << endl;
        return -1;
    }




    for(int i=receive_package.size()-package_length-1;i>0;--i)//去掉尾部多余数据
    {
        receive_package.pop_back();
    }
    for(int i=0;i<receive_package.size();i++)
    {
        cout << hex << "0x" << (int)receive_package[i] << endl;
    }

    uint8 checksum = my_checksum_calculation(receive_package);
    if(receive_package[receive_package.size()-1] != checksum)
    {
        cout << "尾部的校验和错误" << endl;
        return -1;
    }

    if(message_header.message_header_MSB != kMessageHeaderMSB && message_header.message_header_LSB != kMessageHeaderLSB)
    {
        cout << "消息起始头错误" << endl;
        return -1;
    }

    short message_length = message_header.message_length_MSB * 256  + message_header.message_length_LSB;
    if(message_length != package_length - 6)
    {
        cout << "消息包和链路包长度不匹配，返回……" << endl;
        return  -1;
    }
    cout << "消息包长度为:" << "0x" << hex << message_length << endl;


    message_ID = message_header.message_id_MSB*256 + message_header.message_id_LSB;
    cout << "messageID为:" << "0x" << hex << message_ID << endl;

    MessageBase* pMsg = CreateMessageIDptr(message_ID);//记得封装函数销毁，防止内存泄漏
    if(pMsg == nullptr)
    {
        cout << "无当前消息ID" << endl;
        message_ID = 0;
        return -2;
    }

    pMsg->ParameterAnalysis(receive_package,res_package,parameter,message);


    delete  pMsg;//一会回来封装成函数

    return 0;
}


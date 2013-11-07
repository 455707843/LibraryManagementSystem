#pragma once
namespace Config {

    //�û�����
    extern const bool ADMIN_USER;
    extern const bool NORMAL_USER;

    //�û�Ȩ��
    struct USER_ACCESS {
        bool SEARCH_BOOK;       ///����ͼ��
        bool CHANGE_PASSWORD;   ///�޸�����
        bool ADD_USER;          ///����û�
        bool DELETE_USER;       ///ɾ���û�
        bool RESET_PASSWORD;    ///�����û�����
        bool BOLLOW_BOOK;       ///����ͼ��
        bool RETURN_BOOK;       ///�黹ͼ��
        bool RENEW_BOOK;        ///����ͼ��
        bool BOLLOW_HISTORY;    ///�鿴������ʷ
    };
    extern const USER_ACCESS ADMIN_ACCESS;
    extern const USER_ACCESS NORMAL_ACCESS;

    //��������
    extern const int MAX_BOLLOW_TIME;

    //��������
    extern const int MAX_BOLLOW_NUM;
}
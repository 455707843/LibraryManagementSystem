#pragma once
namespace Constant
{
	//�û�����
	const bool ADMIN_USER = true;
	const bool NORMAL_USER = false;

	//�û�Ȩ��
	struct USER_ACCESS{
		bool SEARCH_BOOK;		///����ͼ��
		bool CHANGE_PASSWORD;	///�޸�����
		bool ADD_USER;			///����û�
		bool DELETE_USER;		///ɾ���û�
		bool RESET_PASSWORD;	///�����û�����
		bool BOLLOW_BOOK;		///����ͼ��
		bool RETURN_BOOK;		///�黹ͼ��
		bool RENEW_BOOK;		///����ͼ��
		bool BOLLOW_HISTORY;	///�鿴������ʷ
	}ADMIN_ACCESS, NORMAL_ACCESS;

	//��������
	const int MAX_BOLLOW_TIME = 30;

	//��������
	const int MAX_BOLLOW_NUM = 5;

	void Init();
}
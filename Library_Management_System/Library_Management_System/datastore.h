#ifndef _DATASTORE_H_
#define _DATASTORE_H_

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <direct.h>

namespace Datastore {

	const char* _PATH = ".\\Datastore\\";
	
	struct Book
	{
		int Index;
		bool IsDeleted;
		char Isbn[13];
		char Name[100];
		char Author[100];
		char Pulisher[100];
		int Total;
		int Remain;
	};

	struct User
	{
		int Index;
		bool IsDeleted;
		char Name[100];
		char Password[40];
		char Type[10];
	};

	struct Record
	{
		int Index;
		bool IsDeleted_; // �ݶ�������ɾ��
		int BookIndex;
		int UserIndex;
		int Datetime;
		bool IsRenew;
		bool IsReturned;
	};

	template <typename T>
	char* _GenerateFilePathByType() {
		auto name = typeid(T).name();

		auto lengthName = strlen(name);
		auto lengthPath = strlen(_PATH);
		auto filepath = new char[lengthPath + lengthName + 1];

		strcpy(filepath, _PATH);
		strcpy(filepath + lengthPath, name);

		for (auto i = lengthPath; i < lengthPath + lengthName; i++) {
			auto t = filepath[i];
			if (t == ' ' || t == '/' || t == ':' || t == '*' || t == '?' || 
				t == '"' || t == '<' || t == '>' || t == '|' || t == '\\') {
				filepath[i] = '_';
			}
		}

		return filepath;
	}

	template <typename T>
	FILE* _OpenFile() {
		FILE *file = fopen(_GenerateFilePathByType<T>(), "ab+");
		if (file == NULL) {
			throw new exception("�ļ���ʧ��");
		}
		return file;
	}

	template <typename T>
	bool _IsFileExist() {
		auto file = fopen(_GenerateFilePathByType<T>(), "rb");
		auto exist = true;
		if (file == NULL) {
			exist = false;
		} else {
			fclose(file);
		}
		return exist;
	}

	template <typename T>
	T* Create() {
		auto item = new T();
		memset(item, 0, sizeof T);
		item->Index = -1;
		return item;
	}

	template <typename T>
	T* Select(const int index) {
		auto file = _OpenFile<T>();
		auto size = sizeof T;
		fseek(file, size * index, SEEK_SET);
		auto item = new T();
		fread(item, size, 1, file);
		return item;
	}

	template <typename T>
	T** Select(bool(*where)(T*), const int beginIndex = 0, const int maxCount = 0) {
		auto array = new T[10];
		return array;
	}

	template <typename T>
	void InsertOrUpdate(T* item) {
		auto file = _OpenFile<T>();
		auto size = sizeof T;
		if (item->Index == -1) {
			fseek(file, 0, SEEK_END);
			
		} else {
			auto offset = fseek(file, size * item->Index, SEEK_SET);
			item->Index = offset / size + 1;
		}
		fwrite(item, size, 1, file);
		fclose(file);
	}

	template <typename T>
	void Delete(const int index) {
		auto file = _OpenFile<T>();
		auto size = sizeof T;
		T* item = new T();
		fseek(file, size * index, SEEK_SET);
		fread(item, size, 1, file);
		item->IsDeleted = true;
		fseek(file, size * index, SEEK_SET);
		fwrite(item, size, 1, file);
		fclose(file);
	}

	template <typename T>
	void Traverse(bool(*func)(T*), const int beginIndex = 0, const int endIndex = 0) {
		if (endIndex <= 0) {
			;
		}
	}

	void Init(bool force = false) {
		_mkdir(_PATH);

		if (force || !_IsFileExist<Book>()) {
			fclose(fopen(_GenerateFilePathByType<Book>(), "wb"));
		}
		if (force || !_IsFileExist<User>()) {
			fclose(fopen(_GenerateFilePathByType<User>(), "wb"));

			User* user;
			
			user = Create<User>();
			strcpy(user->Name, "admin");
			strcpy(user->Password, "1");
			strcpy(user->Type, "����Ա");
			InsertOrUpdate(user);
			delete user;

			user = Create<User>();
			strcpy(user->Name, "user");
			strcpy(user->Password, "2");
			strcpy(user->Type, "�û�");
			InsertOrUpdate(user);
			delete user;
		}
		if (force || !_IsFileExist<Record>()) {
			fclose(fopen(_GenerateFilePathByType<Record>(), "wb"));
		}
	}

}

#endif // _DATASTORE_H_